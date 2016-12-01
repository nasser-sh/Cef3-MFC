#include "stdafx.h"
#include "CefClientApp.h"

CCefClientApp::CCefClientApp(
    CefRefPtr<CefBrowserProcessHandler> pBrowserProcessHandler, 
    CefRefPtr<CefRenderProcessHandler> pRenderProcessHandler)
: m_pBrowserProcessHandler(pBrowserProcessHandler)
, m_pRenderProcessHandler(pRenderProcessHandler)
{ }



