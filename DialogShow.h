#pragma once
#include "towar.h"
#include "lista.h"

// CDialogShow dialog

class CDialogShow : public CDialog
{
	DECLARE_DYNAMIC(CDialogShow)

public:
	CDialogShow(CWnd* pParent,lista&,std::vector<unsigned int>&);   // standard constructor
	virtual ~CDialogShow();

// Dialog Data
	enum { IDD = IDD_DIALOG_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	lista& baza_ref;
	std::vector<unsigned int>& indeksy;
	UINT cur_indeks;
	CString nazwa;
	double cena;
	UINT ilosc;
	CString komm;
public:
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	unsigned int i;
};
