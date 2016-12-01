#pragma once
#include <memory>
#include "include/cef_app.h"


class CRenderProcessHandler : public CefRenderProcessHandler
{
public:
    CRenderProcessHandler() = default;
	virtual ~CRenderProcessHandler() = default;

    bool OnProcessMessageReceived(
        CefRefPtr<CefBrowser> browser,
        CefProcessId source_process,
        CefRefPtr<CefProcessMessage> message) override;

private:
	IMPLEMENT_REFCOUNTING(CRenderProcessHandler);
	DISALLOW_COPY_AND_ASSIGN(CRenderProcessHandler);
};