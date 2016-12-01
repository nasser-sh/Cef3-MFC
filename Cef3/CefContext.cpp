#include "stdafx.h"
#include "BrowserProcessHandler.h"
#include "CefContext.h"
#include "CefClientApp.h"
#include "ClientHandler.h"
#include "RenderProcessHandler.h"
#include "include/cef_app.h"
#include "include/cef_base.h"
#include "include/cef_command_line.h"


namespace
{
    CefString const htmlPath = "/html/";

    CefRefPtr<CefCommandLine> GetCefCommandLine()
    {
        CefRefPtr<CefCommandLine> commandLine = CefCommandLine::CreateCommandLine();
        LPWSTR cmd = ::GetCommandLine();
        commandLine->InitFromString(cmd);
        return commandLine;
    }
}


bool CefContext::isInstantiated = false;
wchar_t CefContext::currentDirectory[MAX_PATH];


CefContext::CefContext()
: m_isInit(false)
{ 
    assert(!isInstantiated);
    isInstantiated = true;
    GetCurrentDirectory(MAX_PATH, currentDirectory);
}


CefContext::~CefContext()
{
    Shutdown();
}


CefRefPtr<CefBrowser> CefContext::CreateBrowser(
    CefWindowHandle parentWindow,
    const std::string &url) const
{
    CefWindowInfo windowInfo;
    
    RECT clientRectangle;
    GetClientRect(parentWindow, &clientRectangle);
    windowInfo.SetAsChild(parentWindow, clientRectangle);

    CefBrowserSettings browserSettings;

    return CefBrowserHost::CreateBrowserSync(
        windowInfo, 
        new CClientHandler, 
        CefString(currentDirectory).ToString() + htmlPath.ToString() + url, 
        browserSettings, 
        nullptr);
}


void CefContext::DoMessageLoopWork()
{
    if (isInstantiated) {
        CefDoMessageLoopWork();
    }
}

bool CefContext::IsInit() const
{
    return m_isInit;
}


void CefContext::Init()
{
    if (m_isInit) {
        return;
    }

    m_pApp = new CCefClientApp(
        new CBrowserProcessHandler,
        new CRenderProcessHandler);

    CefMainArgs mainArgs(::GetModuleHandle(nullptr));
    int exitCode = CefExecuteProcess(mainArgs, m_pApp, nullptr);
    ASSERT(exitCode < 0);

    CefSettings settings;
    settings.no_sandbox = true;
    settings.multi_threaded_message_loop = false;

#ifdef DEBUG
    settings.single_process = true;
#endif
    
    m_isInit = CefInitialize(mainArgs, settings, m_pApp, nullptr);
}


void CefContext::Shutdown()
{
    if (m_isInit) {
        CefDoMessageLoopWork();
        CefDoMessageLoopWork();
        CefDoMessageLoopWork();
        CefShutdown();
        m_isInit = false;
    }
}
