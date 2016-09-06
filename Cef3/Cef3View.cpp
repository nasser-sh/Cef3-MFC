
// Cef3View.cpp : implementation of the CCef3View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Cef3.h"
#endif

#include "Cef3Doc.h"
#include "Cef3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCef3View

IMPLEMENT_DYNCREATE(CCef3View, CView)

BEGIN_MESSAGE_MAP(CCef3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCef3View construction/destruction

CCef3View::CCef3View()
{
	// TODO: add construction code here

}

CCef3View::~CCef3View()
{
}

BOOL CCef3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCef3View drawing

void CCef3View::OnDraw(CDC* /*pDC*/)
{
	CCef3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCef3View printing

BOOL CCef3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCef3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCef3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCef3View diagnostics

#ifdef _DEBUG
void CCef3View::AssertValid() const
{
	CView::AssertValid();
}

void CCef3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCef3Doc* CCef3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCef3Doc)));
	return (CCef3Doc*)m_pDocument;
}
#endif //_DEBUG


// CCef3View message handlers
