#pragma once


// CSelectSortView ��ͼ

class CSelectSortView : public CView
{
	DECLARE_DYNCREATE(CSelectSortView)

protected:
	CSelectSortView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSelectSortView();

public:
	//ѡ������
	void OnSelect();
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


