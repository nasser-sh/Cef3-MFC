#include "stdafx.h"
#include "BrowserCtrl.h"
#include "CefClientWindowsMessages.h"
#include "CefIPMessageIDs.h"


#define BROWSER_CTRL_CLASSNAME L"MFCBrowserCtrl"

namespace
{
    // TODO: refactor to MFC Utility
    BOOL RegisterWindowClass()
    {
        WNDCLASS wndcls;
        HINSTANCE hInst = AfxGetInstanceHandle();

        if (!(::GetClassInfo(hInst, BROWSER_CTRL_CLASSNAME, &wndcls))) {
            // otherwise we need to register a new class
            wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
            wndcls.lpfnWndProc = ::DefWindowProc;
            wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
            wndcls.hInstance = hInst;
            wndcls.hIcon = NULL;
            wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
            wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
            wndcls.lpszMenuName = NULL;
            wndcls.lpszClassName = BROWSER_CTRL_CLASSNAME;

            if (!AfxRegisterClass(&wndcls)) {
                AfxThrowResourceException();
                return FALSE;
            }
        }

        return TRUE;
    }

    template <typename T>
    T GetFromLPVoid(LPVOID parameter)
    {
        T *pResult = reinterpret_cast<T*>(parameter);
        assert(pResult != nullptr);
        
        T result = std::move(*pResult);
        delete pResult;

        return result;
    }
}


IMPLEMENT_DYNCREATE(CBrowserCtrl, CWnd)

BEGIN_MESSAGE_MAP(CBrowserCtrl, CWnd)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_MESSAGE(WM_CEF_BROWSER_CREATED, &CBrowserCtrl::OnBrowserCreated)
    ON_MESSAGE(WM_CEF_BROWSER_CLOSE_REQUESTED, &CBrowserCtrl::OnBrowserCloseRequested)
    ON_MESSAGE(WM_CEF_BROWSER_CLOSED, &CBrowserCtrl::OnBrowserClosed)
END_MESSAGE_MAP()


CefContext CBrowserCtrl::cefContext;


void CBrowserCtrl::DoMessageLoopWork()
{
    cefContext.DoMessageLoopWork();
}


CBrowserCtrl::CBrowserCtrl()
{ 
    RegisterWindowClass();
}


CBrowserCtrl::~CBrowserCtrl()
{ }


BOOL CBrowserCtrl::Create(CWnd *pParent, std::string url)
{
    DWORD dwStyle = WS_CHILD | WS_VISIBLE;
    std::string *pUrl = new std::string(std::move(url));

    return CWnd::CreateEx(
        0,
        BROWSER_CTRL_CLASSNAME,
        L"",
        dwStyle,
        CRect(0, 0, 0, 0),
        pParent,
        NULL,
        (LPVOID)pUrl);
}


void CBrowserCtrl::OnClose()
{
    CWnd::OnClose();
    m_pBrowser->GetHost()->CloseBrowser(false);
}


int CBrowserCtrl::OnCreate(LPCREATESTRUCT pCreateStruct)
{
    if (CWnd::OnCreate(pCreateStruct) == -1) {
        return -1;
    }

    std::string url = GetFromLPVoid<std::string>(pCreateStruct->lpCreateParams);

    HWND hWnd = GetSafeHwnd();
    m_pBrowser = cefContext.CreateBrowser(hWnd, url);

    return 0;
}


void CBrowserCtrl::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    if (!m_pBrowser) {
        return;
    }

    HWND hWnd = m_pBrowser->GetHost()->GetWindowHandle();

    CRect rect;
    GetClientRect(&rect);

    HDWP hDwp = BeginDeferWindowPos(1);
    hDwp = DeferWindowPos(
        hDwp,
        hWnd,
        NULL,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        SWP_NOZORDER);
    EndDeferWindowPos(hDwp);
}


void CBrowserCtrl::ExecuteJS(
    const std::string &function, 
    const std::string &arguments)
{
    CefString jsCall = function + "(" + arguments + ")";
    CefRefPtr<CefFrame> pFrame = m_pBrowser->GetMainFrame();
    pFrame->ExecuteJavaScript(jsCall, pFrame->GetURL(), 0);
    // CefRefPtr<CefProcessMessage> pMessage = CefProcessMessage::Create(IP_MESSAGE_EXECUTE_JS);
    // CefRefPtr<CefListValue> jsArguments = pMessage->GetArgumentList();
    // jsArguments->SetString(0, jsCall);
    // m_pBrowser->SendProcessMessage(PID_RENDERER, pMessage);
}


LRESULT CBrowserCtrl::OnBrowserCreated(WPARAM wParam, LPARAM lParam)
{
    // Do nothing
    return S_OK;
}

LRESULT CBrowserCtrl::OnBrowserCloseRequested(WPARAM wParam, LPARAM lParam)
{
    // Do nothing
    return S_OK;
}

LRESULT CBrowserCtrl::OnBrowserClosed(WPARAM wParam, LPARAM lParam)
{
    m_pBrowser = nullptr;
    return S_OK;
}
