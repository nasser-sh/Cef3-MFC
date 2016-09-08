#pragma once
#include "include/cef_app.h"


class CCefOtherApp : public CefApp
{
public:
	CCefOtherApp() = default;

private:
	IMPLEMENT_REFCOUNTING(CCefOtherApp);
	DISALLOW_COPY_AND_ASSIGN(CCefOtherApp);
};