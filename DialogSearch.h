#pragma once
#include "towar.h"
#include "lista.h"

// CDialogSearch dialog

class CDialogSearch : public CDialog
{
	DECLARE_DYNAMIC(CDialogSearch)

public:
	CDialogSearch(CWnd* pParent,lista&);   // standard constructor
	virtual ~CDialogSearch();

// Dialog Data
	enum { IDD = IDD_DIALOG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	lista& baza_ref;
	CString nazwa;
	BOOL uzyj_nazwy;
	BOOL uzyj_ceny;
	BOOL uzyj_ilosci;
	BOOL czy_zakres_ceny;
	BOOL czy_zakres_ilosci;
	double cena;
	double cena_lo;
	double cena_hi;
	UINT ilosc;
	UINT ilosc_lo;
	UINT ilosc_hi;
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton1();
};
