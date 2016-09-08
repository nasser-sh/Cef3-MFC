#pragma once
#include <string>
#include "include/cef_app.h"


class CefContext
{
public:
	CefContext();
	CefRefPtr<CefBrowser> CreateBrowser(
		CefWindowHandle parentWindow,
		const std::string &url) const;
	void DoMessageLoopWork();
	bool Initialize();
	bool IsInitialized() const;
	void Shutdown();

private:
	bool m_initialized;
	CefRefPtr<CefApp> m_pApp;
};