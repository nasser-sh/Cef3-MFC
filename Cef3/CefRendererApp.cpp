#include "stdafx.h"
#include "CefRendererApp.h"
#include "CefIPMessageIDs.h"


CCefRendererApp::~CCefRendererApp()
{ }


bool CCefRendererApp::OnProcessMessageReceived(
    CefRefPtr<CefBrowser> pBrowser, 
    CefProcessId sourceProcess, 
    CefRefPtr<CefProcessMessage> pMessage)
{
    if (pMessage->GetName() == IP_MESSAGE_EXECUTE_JS) {
        CefRefPtr<CefListValue> arguments = pMessage->GetArgumentList();
        CefString toCall = arguments->GetString(0);
        CefRefPtr<CefFrame> pFrame = pBrowser->GetMainFrame();
        pFrame->ExecuteJavaScript(toCall, pFrame->GetURL(), 0);
        return true;
    }

    return false;
}
