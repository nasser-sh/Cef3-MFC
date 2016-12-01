#pragma once
#include <memory>
#include "include/cef_app.h"


class CBrowserProcessHandler : public CefBrowserProcessHandler
{
public:
    CBrowserProcessHandler() = default;
	virtual ~CBrowserProcessHandler() = default;

private:
	IMPLEMENT_REFCOUNTING(CBrowserProcessHandler);
	DISALLOW_COPY_AND_ASSIGN(CBrowserProcessHandler);
};