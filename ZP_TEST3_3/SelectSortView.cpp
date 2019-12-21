// SelectSortView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "SelectSortView.h"
#include "ZP_TEST3_3Doc.h"


// CSelectSortView

IMPLEMENT_DYNCREATE(CSelectSortView, CView)

CSelectSortView::CSelectSortView()
{

}

CSelectSortView::~CSelectSortView()
{
}

BEGIN_MESSAGE_MAP(CSelectSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CSelectSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CSelectSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CSelectSortView::OnStop)
END_MESSAGE_MAP()
void CSelectSortView::OnSelect()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	int minIndex=pDoc->CompC;
	for (int j = pDoc->CompC; j < pDoc->num; j++)
	{
		if (pDoc->SelectA[minIndex]>pDoc->SelectA[j])
		{
			minIndex=j;
		}
	}
	int t=pDoc->SelectA[minIndex];
	pDoc->SelectA[minIndex]=pDoc->SelectA[pDoc->CompC];
	pDoc->SelectA[pDoc->CompC]=t;
	pDoc->CompC++;

}

// CSelectSortView ��ͼ

void CSelectSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//��ȡ�ĵ�ָ��
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	//�����ֱ���
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("ѡ������"));
	//�����о���
	for (int i = 0; i < pDoc->num; i++)
	{
		//���㵱ǰ����
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->SelectA[i]);
		//��ǰ���β���ѡ��
		if (i!=pDoc->CompC)
		{
			//����ɫɫ��ˢ���
			pDC->FillRect(Rect,pDoc->gBrush);
		}
		else
		{
			//�ú�ɫ��ˢ
			pDC->FillRect(Rect,pDoc->rBrush);
		}
	}
	//��û���źþͼ�������
	if (pDoc->CompC<pDoc->num-1)
	{
		OnSelect();
	}
}


// CSelectSortView ���

#ifdef _DEBUG
void CSelectSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectSortView ��Ϣ�������


void CSelectSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CSelectSortView::OnOnestep()
{
	// TODO: �ڴ���������������
	KillTimer(1);
	Invalidate(TRUE);
}


void CSelectSortView::OnAuto()
{
	// TODO: �ڴ���������������
	SetTimer(1,1000,0);
}


void CSelectSortView::OnStop()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}
