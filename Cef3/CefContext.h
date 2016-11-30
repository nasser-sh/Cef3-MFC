#pragma once
#include <string>
#include "include/cef_app.h"


class CefContext final
{
public:
    CefContext();
    ~CefContext();
    
    CefRefPtr<CefBrowser> CreateBrowser(
        CefWindowHandle parentWindow,
        const std::string &url) const;

    void DoMessageLoopWork();
    bool IsInit() const;
    void Init();
    void Shutdown();

private:
    static bool isInstantiated;
	static wchar_t currentDirectory[MAX_PATH];

    CefRefPtr<CefApp> m_pApp;
    bool m_isInit;
};