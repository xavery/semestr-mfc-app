#pragma once
#include "towar.h"
#include "lista.h"

// DialogEdit dialog

class DialogEdit : public CDialog
{
	DECLARE_DYNAMIC(DialogEdit)

public:
	DialogEdit(CWnd* pParent,lista&);   // standard constructor
	virtual ~DialogEdit();

// Dialog Data
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	lista& baza_ref;
	UINT akt_indeks;
	CString nazwa;
	double cena;
	UINT ilosc;
	CString koment;
public:
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
