#pragma once


// CDialogAdd dialog
#include "towar.h"
#include "lista.h"

class CDialogAdd : public CDialog
{
	DECLARE_DYNAMIC(CDialogAdd)

public:
	//CDialogAdd(CWnd* pParent = NULL,lista&);   // standard constructor
	CDialogAdd(CWnd* pParent,lista&);   // standard constructor
	virtual ~CDialogAdd();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	lista &baza_ref;
	UINT akt_indeks;
	CString nazwa;
	double cena;
	UINT ilosc;
	CString komm;
public:
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedOk();
};
