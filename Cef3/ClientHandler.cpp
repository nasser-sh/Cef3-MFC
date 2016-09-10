#include "stdafx.h"
#include "ClientHandler.h"
#include "CefClientWindowsMessages.h"


namespace
{
    CefWindowHandle GetBrowserParent(CefRefPtr<CefBrowser> const &pBrowser)
    {
        return ::GetParent(pBrowser->GetHost()->GetWindowHandle());
    }
}


CClientHandler::CClientHandler()
{ }


CClientHandler::~CClientHandler()
{ }


void CClientHandler::OnAfterCreated(CefRefPtr<CefBrowser> pBrowser) 
{
    CefWindowHandle hWnd = GetBrowserParent(pBrowser);
    ::SendMessage(hWnd, WM_CEF_BROWSER_CREATED, (WPARAM)&pBrowser, NULL);
}


bool CClientHandler::DoClose(CefRefPtr<CefBrowser> pBrowser)
{
    CefWindowHandle hWnd = GetBrowserParent(pBrowser);
    ::SendMessage(hWnd, WM_CEF_BROWSER_CLOSE_REQUESTED, (WPARAM)&pBrowser, NULL);
    return false;
}


void CClientHandler::OnBeforeClose(CefRefPtr<CefBrowser> pBrowser)
{
    CefWindowHandle hWnd = GetBrowserParent(pBrowser);
    ::SendMessage(hWnd, WM_CEF_BROWSER_CLOSED, (WPARAM)&pBrowser, NULL);
}