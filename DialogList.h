#pragma once


// CDialogList dialog
#include "towar.h"
#include "lista.h"
#include "afxcmn.h"

class CDialogList : public CDialog
{
	DECLARE_DYNAMIC(CDialogList)

public:
	CDialogList(CWnd* pParent,lista&);   // standard constructor
	virtual ~CDialogList();

// Dialog Data
	enum { IDD = IDD_DIALOG_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
private:
	lista& baza_ref;
};
