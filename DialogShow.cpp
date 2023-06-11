// DialogShow.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "DialogShow.h"


// CDialogShow dialog

IMPLEMENT_DYNAMIC(CDialogShow, CDialog)

CDialogShow::CDialogShow(CWnd* pParent /*=NULL*/,lista& bref,std::vector<unsigned int> &ind)
	: CDialog(CDialogShow::IDD, pParent)
	, indeksy(ind)
	, baza_ref(bref)
	, cur_indeks(0)
	, nazwa(_T(""))
	, cena(0)
	, ilosc(0)
	, komm(_T(""))
	, i(0)
{
}

CDialogShow::~CDialogShow()
{
}

void CDialogShow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cur_indeks);
	DDX_Text(pDX, IDC_EDIT2, nazwa);
	DDX_Text(pDX, IDC_EDIT3, cena);
	DDX_Text(pDX, IDC_EDIT4, ilosc);
	DDX_Text(pDX, IDC_EDIT5, komm);
}


BEGIN_MESSAGE_MAP(CDialogShow, CDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDialogShow::OnDeltaposSpin1)
END_MESSAGE_MAP()

BOOL CDialogShow::OnInitDialog()
{
	cur_indeks = indeksy[i];
	towar bla = baza_ref.zwroc(cur_indeks);
	nazwa = bla.getnazwa();
	cena = bla.getcena();
	ilosc = bla.getilosc();
	komm = bla.getkoment();
	UpdateData(FALSE);
	return TRUE;
}
// CDialogShow message handlers

void CDialogShow::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	towar temp;
	if(pNMUpDown->iDelta < 0)
	{
		if((i + 1) >= indeksy.size()) return;
		++i;
	}
	else
	{
		if(i == 0) return;
		--i;
	}
	cur_indeks = indeksy[i];
	temp = baza_ref.zwroc(cur_indeks);
	nazwa = temp.getnazwa();
	cena = temp.getcena();
	ilosc = temp.getilosc();
	komm = temp.getkoment();
	UpdateData(FALSE);
	*pResult = 0;
}
