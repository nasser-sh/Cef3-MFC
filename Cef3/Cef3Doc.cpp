
// Cef3Doc.cpp : implementation of the CCef3Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Cef3.h"
#endif

#include "Cef3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCef3Doc

IMPLEMENT_DYNCREATE(CCef3Doc, CDocument)

BEGIN_MESSAGE_MAP(CCef3Doc, CDocument)
END_MESSAGE_MAP()


// CCef3Doc construction/destruction

CCef3Doc::CCef3Doc()
{
    // TODO: add one-time construction code here

}

CCef3Doc::~CCef3Doc()
{
}

BOOL CCef3Doc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)

    return TRUE;
}




// CCef3Doc serialization

void CCef3Doc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO: add storing code here
    }
    else
    {
        // TODO: add loading code here
    }
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CCef3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // Modify this code to draw the document's data
    dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

    CString strText = _T("TODO: implement thumbnail drawing here");
    LOGFONT lf;

    CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
    pDefaultGUIFont->GetLogFont(&lf);
    lf.lfHeight = 36;

    CFont fontDraw;
    fontDraw.CreateFontIndirect(&lf);

    CFont* pOldFont = dc.SelectObject(&fontDraw);
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
    dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CCef3Doc::InitializeSearchContent()
{
    CString strSearchContent;
    // Set search contents from document's data. 
    // The content parts should be separated by ";"

    // For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
    SetSearchContent(strSearchContent);
}

void CCef3Doc::SetSearchContent(const CString& value)
{
    if (value.IsEmpty())
    {
        RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
    }
    else
    {
        CMFCFilterChunkValueImpl *pChunk = NULL;
        ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
        if (pChunk != NULL)
        {
            pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
            SetChunkValue(pChunk);
        }
    }
}

#endif // SHARED_HANDLERS

// CCef3Doc diagnostics

#ifdef _DEBUG
void CCef3Doc::AssertValid() const
{
    CDocument::AssertValid();
}

void CCef3Doc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG


// CCef3Doc commands
