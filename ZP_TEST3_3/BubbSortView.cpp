// BubbSortView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "BubbSortView.h"
#include "ZP_TEST3_3Doc.h"

// CBubbSortView

IMPLEMENT_DYNCREATE(CBubbSortView, CView)

CBubbSortView::CBubbSortView()
{

}

CBubbSortView::~CBubbSortView()
{
}

BEGIN_MESSAGE_MAP(CBubbSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CBubbSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CBubbSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CBubbSortView::OnStop)
END_MESSAGE_MAP()

void CBubbSortView::OnBubb()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	if (pDoc->CompB!=0)
	{
		if (pDoc->BubbA[pDoc->CompB]<pDoc->BubbA[pDoc->CompB-1])
		{
			int t=pDoc->BubbA[pDoc->CompB];
			pDoc->BubbA[pDoc->CompB]=pDoc->BubbA[pDoc->CompB-1];
			pDoc->BubbA[pDoc->CompB-1]=t;
		}
	}
	pDoc->CompB++;
	if(pDoc->CompB==pDoc->num-pDoc->CompB_Count)
	{
		pDoc->CompB_Count++;
		pDoc->CompB=0;
	}
}

// CBubbSortView ��ͼ

void CBubbSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//��ȡ�ĵ�ָ��
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	//�����ֱ���
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("ð������"));
	for (int i = 0; i < pDoc->num; i++)
	{
		//���㵱ǰ����
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->BubbA[i]);
		//��ǰ���β���ѡ��
		if (i!=pDoc->CompB)
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
	if (pDoc->CompB_Count<pDoc->num)
	{
		OnBubb();
	}
}


// CBubbSortView ���

#ifdef _DEBUG
void CBubbSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CBubbSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBubbSortView ��Ϣ�������


void CBubbSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CBubbSortView::OnOnestep()
{
	// TODO: �ڴ���������������
	KillTimer(1);
	Invalidate(TRUE);
}


void CBubbSortView::OnAuto()
{
	// TODO: �ڴ���������������
	SetTimer(1,1000,0);
}


void CBubbSortView::OnStop()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}
