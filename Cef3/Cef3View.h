
// Cef3View.h : interface of the CCef3View class
//

#pragma once
#include "BrowserCtrl.h"

class CCef3View : public CView
{
protected: // create from serialization only
    CCef3View();
    DECLARE_DYNCREATE(CCef3View)

// Attributes
public:
    CCef3Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
    virtual ~CCef3View();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    CBrowserCtrl m_browserCtrl;
// Generated message map functions
protected:
    afx_msg void OnAddJS();
    afx_msg int OnCreate(LPCREATESTRUCT pCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Cef3View.cpp
inline CCef3Doc* CCef3View::GetDocument() const
   { return reinterpret_cast<CCef3Doc*>(m_pDocument); }
#endif

