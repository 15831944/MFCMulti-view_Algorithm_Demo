#pragma once


// CInsertSortView ��ͼ

class CInsertSortView : public CView
{
	DECLARE_DYNCREATE(CInsertSortView)

protected:
	CInsertSortView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CInsertSortView();

public:
	//��������
	void OnInsert();


	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnOnestep();
	afx_msg void OnAuto();
	afx_msg void OnStop();
};


