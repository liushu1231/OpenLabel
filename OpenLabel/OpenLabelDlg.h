
// OpenLabelDlg.h : 头文件
//

#pragma once

#include<vector>
#include<stdio.h>
#include "afxwin.h"

typedef struct box{
	int id;
	int x;
	int y;
	int w;
	int h;
}Box;


// COpenLabelDlg 对话框
class COpenLabelDlg : public CDialogEx
{
// 构造
public:
	COpenLabelDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OPENLABEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int InitResource(void);

public:
	afx_msg void OnBnClickedExplore();
	afx_msg void OnBnClickedOpenfile();

	void DisplayImage(HWND hWnd,IplImage* pImage);

private:
	CvCapture* m_pCapture;
	int m_iCurrentNum;
	FILE* m_pLabelFile;
	vector<Box> m_Boxes;
	CEdit m_ctrlLabelFilePath;
	CButton m_ctrlStartLabel;
	CButton m_ctrlNextFrame;
	CButton m_ctrlUndo;
	CButton m_ctrlClear;
	CButton m_ctrlRestart;
	CButton m_ctrlDone;
	CStatic m_ctrlTextFrameNum;
public:
	afx_msg void OnBnClickedStart();
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	float m_fWRatio;
	float m_fHRatio;
	Box m_curBox;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	bool m_bDrawFlag;
	POINT m_ptOld;
	POINT m_ptOrigin;
public:
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedClearcurrent();
	afx_msg void OnBnClickedRestart();
	afx_msg void OnBnClickedDone();
private:
	IplImage* m_pCurrentFrame;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnDestroy();
private:
	bool m_bStarted;
	int m_iOffsetX;
	int m_iOffsetY;
};
