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

private:
	bool Initialize();
	void Shutdown();

private:
	static bool isInstantiated;
	CefRefPtr<CefApp> m_pApp;
};