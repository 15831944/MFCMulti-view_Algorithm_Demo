
// ZP_TEST3_3View.cpp : CZP_TEST3_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZP_TEST3_3.h"
#endif

#include "ZP_TEST3_3Doc.h"
#include "ZP_TEST3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZP_TEST3_3View

IMPLEMENT_DYNCREATE(CZP_TEST3_3View, CView)

BEGIN_MESSAGE_MAP(CZP_TEST3_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZP_TEST3_3View ����/����

CZP_TEST3_3View::CZP_TEST3_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CZP_TEST3_3View::~CZP_TEST3_3View()
{
}

BOOL CZP_TEST3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZP_TEST3_3View ����

void CZP_TEST3_3View::OnDraw(CDC* /*pDC*/)
{
	CZP_TEST3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CZP_TEST3_3View ��ӡ

BOOL CZP_TEST3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZP_TEST3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZP_TEST3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZP_TEST3_3View ���

#ifdef _DEBUG
void CZP_TEST3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_TEST3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_TEST3_3Doc* CZP_TEST3_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_TEST3_3Doc)));
	return (CZP_TEST3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZP_TEST3_3View ��Ϣ�������
