// InsertSortView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "InsertSortView.h"
#include "MainFrm.h"
#include "ZP_TEST3_3Doc.h"


// CInsertSortView

IMPLEMENT_DYNCREATE(CInsertSortView, CView)

CInsertSortView::CInsertSortView()
{
}

CInsertSortView::~CInsertSortView()
{
}

BEGIN_MESSAGE_MAP(CInsertSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CInsertSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CInsertSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CInsertSortView::OnStop)
END_MESSAGE_MAP()


// CInsertSortView ��ͼ

void CInsertSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//��ȡ�ĵ�ָ��
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	//�����ֱ���
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("��������"));
	//�����о���
	for (int i = 0; i < pDoc->num; i++)
	{
		//���㵱ǰ����
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->InsertA[i]);
		//��ǰ���β���ѡ��
		if (i!=pDoc->CompA)
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
	if (pDoc->CompA<pDoc->num)
	{
		OnInsert();
	}
}


// CInsertSortView ���

#ifdef _DEBUG
void CInsertSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CInsertSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInsertSortView ��Ϣ�������


void CInsertSortView::OnInsert()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	int minIndex=0;
	for (int j = 0; j < pDoc->CompA; j++)
	{
		if (pDoc->InsertA[pDoc->CompA]<pDoc->InsertA[j])
		{
			minIndex=j;
			int t=pDoc->InsertA[pDoc->CompA];
			pDoc->InsertA[pDoc->CompA]=pDoc->InsertA[j];
			pDoc->InsertA[j]=t;
		}
	}
	if (pDoc->CompA<pDoc->num-1)
	{
		pDoc->CompA++;
	}
}

void CInsertSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CInsertSortView::OnOnestep()
{
	// TODO: �ڴ���������������
	KillTimer(1);
	Invalidate(TRUE);
}


void CInsertSortView::OnAuto()
{
	// TODO: �ڴ���������������
	SetTimer(1,1000,0);
	//Invalidate(TRUE);
}


void CInsertSortView::OnStop()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}
