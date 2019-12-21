
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"

#include "MainFrm.h"
#include "InsertSortWnd.h"
#include "InsertSortView.h"
#include "BubbSortView.h"
#include "SelectSortView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_SELECT, &CMainFrame::OnSelect)
	ON_COMMAND(ID_INSERT, &CMainFrame::OnInsert)
	ON_COMMAND(ID_BUBB, &CMainFrame::OnBubb)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::OnSelect()
{
	// TODO: �ڴ���������������
	//��ȡAPPָ��
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//��ȡ�ĵ�ָ��
	CDocument* myDoc= myApp->pSelectDocTemplate->CreateNewDocument();
	//��ȡ���ָ��
	CFrameWnd* myFrame=	myApp->pSelectDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//��ʼ�����
	myApp->pSelectDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//��ȡ��Ӧ����ͼ
	CSelectSortView* pview=(CSelectSortView*)(myFrame->GetActiveView());
}


void CMainFrame::OnInsert()
{
	// TODO: �ڴ���������������
	//��ȡAPPָ��
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//��ȡ�ĵ�ָ��
	CDocument* myDoc= myApp->pInsertDocTemplate->CreateNewDocument();
	//��ȡ���ָ��
	CFrameWnd* myFrame=	myApp->pInsertDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//��ʼ�����
	myApp->pInsertDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//��ȡ��Ӧ����ͼ
	CInsertSortView* pview=(CInsertSortView*)(myFrame->GetActiveView());

}
void CMainFrame::OnBubb()
{
	// TODO: �ڴ���������������
	//��ȡAPPָ��
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//��ȡ�ĵ�ָ��
	CDocument* myDoc= myApp->pBubbDocTemplate->CreateNewDocument();
	//��ȡ���ָ��
	CFrameWnd* myFrame=	myApp->pBubbDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//��ʼ�����
	myApp->pBubbDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//��ȡ��Ӧ����ͼ
	CBubbSortView* pview=(CBubbSortView*)(myFrame->GetActiveView());
}
