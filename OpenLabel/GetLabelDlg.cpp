// GetLabelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenLabel.h"
#include "GetLabelDlg.h"
#include "afxdialogex.h"


// CGetLabelDlg dialog

IMPLEMENT_DYNAMIC(CGetLabelDlg, CDialog)

CGetLabelDlg::CGetLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetLabelDlg::IDD, pParent)
	, m_strLable(_T(""))
{
	
}

CGetLabelDlg::~CGetLabelDlg()
{
}

void CGetLabelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetLabelDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CGetLabelDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGetLabelDlg message handlers


void CGetLabelDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	GetDlgItem(IDC_EDIT1)->GetWindowTextA(this->m_strLable);
	int label = atoi(m_strLable);
	if(label > -1)
		EndDialog(label);
	else
		MessageBox("Wrong Label");
}


BOOL CGetLabelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	DWORD dwStyle = GetWindowLong(m_hWnd, GWL_STYLE);
	dwStyle &= ~WS_MAXIMIZEBOX;
	dwStyle &= ~WS_MINIMIZEBOX;
	dwStyle &= ~WS_MINIMIZEBOX;
	dwStyle &= ~WS_SYSMENU;
	SetWindowLong(m_hWnd,GWL_STYLE,dwStyle);

	HWND hWnd = NULL;
	GetDlgItem(IDC_EDIT1,&hWnd);
	::SetFocus(hWnd);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
