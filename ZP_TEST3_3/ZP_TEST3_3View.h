
// ZP_TEST3_3View.h : CZP_TEST3_3View ��Ľӿ�
//

#pragma once


class CZP_TEST3_3View : public CView
{
protected: // �������л�����
	CZP_TEST3_3View();
	DECLARE_DYNCREATE(CZP_TEST3_3View)

// ����
public:
	CZP_TEST3_3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CZP_TEST3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ZP_TEST3_3View.cpp �еĵ��԰汾
inline CZP_TEST3_3Doc* CZP_TEST3_3View::GetDocument() const
   { return reinterpret_cast<CZP_TEST3_3Doc*>(m_pDocument); }
#endif

