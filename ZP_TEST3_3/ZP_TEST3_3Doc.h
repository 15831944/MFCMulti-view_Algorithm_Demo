
// ZP_TEST3_3Doc.h : CZP_TEST3_3Doc ��Ľӿ�
//


#pragma once


class CZP_TEST3_3Doc : public CDocument
{
protected: // �������л�����
	CZP_TEST3_3Doc();
	DECLARE_DYNCREATE(CZP_TEST3_3Doc)

// ����
public:
	void InitData();
// ����
public:
	//������������
	int InsertA[100];
	//��������ǰѡ�������λ��
	int CompA;
	//ð������ǰѡ�������λ��
	int CompB;
	//ð�������Ѿ��źõ����ĸ���
	int CompB_Count;
	//ѡ������ǰѡ�������λ��
	int CompC;
	//������������
	int SelectA[100];
	//������������
	int BubbA[100];
	//���ĸ���
	int num;
	//����֮���X���
	int SpaceX;
	//������߶ȵı�
	int LevelY;
	//���ο��
	int width;
	//��ɫ��ˢ
	CBrush *rBrush;
	//��ɫ��ˢ
	CBrush *gBrush;
	//��ɫ��ˢ
	CBrush *wBrush;
	//���½������
	POINT LeftBottom;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CZP_TEST3_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnInitdata();
};
