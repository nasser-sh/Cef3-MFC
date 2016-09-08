
// Cef3.h : main header file for the Cef3 application
//
#pragma once
#include "CefContext.h"

#ifndef __AFXWIN_H__
    #error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCef3App:
// See Cef3.cpp for the implementation of this class
//

class CCef3App : public CWinApp
{
public:
    CCef3App();


// Overrides
public:
    virtual BOOL InitInstance() override;
    virtual int ExitInstance() override;
	virtual BOOL PumpMessage() override;

private:
	CefContext m_cefContext;

protected:
// Implementation
    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};

extern CCef3App theApp;
