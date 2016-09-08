#pragma once
#include <memory>
#include "include/cef_app.h"


class CCefRendererApp :
	public CefApp,
	public CefRenderProcessHandler
{
public:
	CCefRendererApp() = default;
	virtual ~CCefRendererApp();

	CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override { return this; }

private:
	IMPLEMENT_REFCOUNTING(CCefRendererApp);
	DISALLOW_COPY_AND_ASSIGN(CCefRendererApp);
};