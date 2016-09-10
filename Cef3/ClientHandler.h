#pragma once
#include "include/cef_client.h"


class CClientHandler : 
    public CefClient,
    public CefLifeSpanHandler
{
public:
    CClientHandler();
    virtual ~CClientHandler();

    CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override { return this; }
    void OnAfterCreated(CefRefPtr<CefBrowser> pBrowser) override;
    bool DoClose(CefRefPtr<CefBrowser> pBrowser) override;
    void OnBeforeClose(CefRefPtr<CefBrowser> pBrowser) override;

private:

    IMPLEMENT_REFCOUNTING(CClientHandler);
};

