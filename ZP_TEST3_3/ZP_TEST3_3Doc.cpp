
// ZP_TEST3_3Doc.cpp : CZP_TEST3_3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZP_TEST3_3.h"
#endif

#include "ZP_TEST3_3Doc.h"

#include <propkey.h>
//#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZP_TEST3_3Doc

IMPLEMENT_DYNCREATE(CZP_TEST3_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CZP_TEST3_3Doc, CDocument)
	ON_COMMAND(ID_INITDATA, &CZP_TEST3_3Doc::OnInitdata)
END_MESSAGE_MAP()


// CZP_TEST3_3Doc ����/����

CZP_TEST3_3Doc::CZP_TEST3_3Doc()
{
	// TODO: �ڴ����һ���Թ������
	InitData();
}

CZP_TEST3_3Doc::~CZP_TEST3_3Doc()
{
}
void CZP_TEST3_3Doc::InitData()
{
	num=20;
	srand((unsigned)time(NULL));
	for (int i=0;i<num;i++)
	{
		InsertA[i]=int((rand()%90+11));
		SelectA[i]=InsertA[i];
		BubbA[i]=InsertA[i];
	}
	SpaceX=10;
	width=20;
	LevelY=1;
	LeftBottom.x=10;
	LeftBottom.y=200;
	gBrush=new CBrush(RGB(0,255,0));
	gBrush->CreateObject();
	rBrush=new CBrush(RGB(255,0,0));
	rBrush->CreateObject();
	wBrush=new CBrush(RGB(255,255,255));
	wBrush->CreateObject();
	CompA=0;
	CompB=0;
	CompB_Count=0;
	CompC=0;
}
BOOL CZP_TEST3_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CZP_TEST3_3Doc ���л�

void CZP_TEST3_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CZP_TEST3_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CZP_TEST3_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CZP_TEST3_3Doc::SetSearchContent(const CString& value)
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

// CZP_TEST3_3Doc ���

#ifdef _DEBUG
void CZP_TEST3_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZP_TEST3_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZP_TEST3_3Doc ����


void CZP_TEST3_3Doc::OnInitdata()
{
	// TODO: �ڴ���������������
	InitData();
	UpdateAllViews(NULL);
}
