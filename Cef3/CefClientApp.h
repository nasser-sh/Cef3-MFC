#pragma once
#include "include/cef_app.h"


class CCefClientApp : public CefApp
{
public:
    CCefClientApp(
        CefRefPtr<CefBrowserProcessHandler> pBrowserProcessHandler,
        CefRefPtr<CefRenderProcessHandler> pRenderProcessHandler);

    CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override { return m_pBrowserProcessHandler; }
    CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override { return m_pRenderProcessHandler; }

private:
    CefRefPtr<CefBrowserProcessHandler> m_pBrowserProcessHandler;
    CefRefPtr<CefRenderProcessHandler> m_pRenderProcessHandler;

    DISALLOW_COPY_AND_ASSIGN(CCefClientApp);
    IMPLEMENT_REFCOUNTING(CCefClientApp);
};

