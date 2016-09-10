#include "stdafx.h"
#include "BrowserCtrl.h"
#include "CefClientWindowsMessages.h"


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


BOOL CBrowserCtrl::Create(CWnd *pParent)
{
    DWORD dwStyle = WS_CHILD | WS_VISIBLE;
    
    return CWnd::Create(
        BROWSER_CTRL_CLASSNAME,
        L"",
        dwStyle,
        CRect(0, 0, 0, 0),
        pParent,
        NULL);
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

    HWND hWnd = GetSafeHwnd();
    m_pBrowser = cefContext.CreateBrowser(hWnd, "https://www.google.com");

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
