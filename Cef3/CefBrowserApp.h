#pragma once
#include <memory>
#include "include/cef_app.h"


class CCefBrowserApp :
	public CefApp,
	public CefBrowserProcessHandler
{
public:
	CCefBrowserApp() = default;
	virtual ~CCefBrowserApp();

	CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override { return this; }

private:
	IMPLEMENT_REFCOUNTING(CCefBrowserApp);
	DISALLOW_COPY_AND_ASSIGN(CCefBrowserApp);
};