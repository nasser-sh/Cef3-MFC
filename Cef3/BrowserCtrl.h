#pragma once
#include <afxwin.h>
#include <string>
#include "CefContext.h"

class CBrowserCtrl : public CWnd
{
    DECLARE_DYNCREATE(CBrowserCtrl)
public:
    CBrowserCtrl();
    virtual ~CBrowserCtrl();

    static void DoMessageLoopWork();

    BOOL Create(CWnd *pParent, std::string url);

private:
    static CefContext cefContext;

    CefRefPtr<CefBrowser> m_pBrowser;

protected:
    afx_msg void OnClose();
    afx_msg int OnCreate(LPCREATESTRUCT pCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg LRESULT OnBrowserCreated(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnBrowserCloseRequested(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnBrowserClosed(WPARAM wParam, LPARAM lParam);
    DECLARE_MESSAGE_MAP()
};

