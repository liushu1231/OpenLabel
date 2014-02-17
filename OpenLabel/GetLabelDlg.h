#pragma once


// CGetLabelDlg dialog

class CGetLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetLabelDlg)

public:
	CGetLabelDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGetLabelDlg();

// Dialog Data
	enum { IDD = IDD_GETIDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strLable;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
