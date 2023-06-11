// DialogAdd.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "DialogAdd.h"


// CDialogAdd dialog

IMPLEMENT_DYNAMIC(CDialogAdd, CDialog)

CDialogAdd::CDialogAdd(CWnd* pParent /*=NULL*/,lista &bzref)
	: CDialog(CDialogAdd::IDD, pParent)
	, baza_ref(bzref)
	, akt_indeks(0)
	, nazwa(_T(""))
	, cena(0)
	, ilosc(0)
	, komm(_T(""))
{

}

CDialogAdd::~CDialogAdd()
{
}

void CDialogAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, akt_indeks);
	DDX_Text(pDX, IDC_EDIT2, nazwa);
	DDX_Text(pDX, IDC_EDIT3, cena);
	DDX_Text(pDX, IDC_EDIT4, ilosc);
	DDX_Text(pDX, IDC_EDIT5, komm);
}

BOOL CDialogAdd::OnInitDialog()
{
	akt_indeks = baza_ref.getwielkosc()+1;
	UpdateData(FALSE);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CDialogAdd, CDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CDialogAdd::OnDeltaposSpin2)
	ON_EN_CHANGE(IDC_EDIT3, &CDialogAdd::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CDialogAdd::OnEnChangeEdit4)
	ON_BN_CLICKED(IDOK, &CDialogAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogAdd message handlers

void CDialogAdd::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if(pNMUpDown->iDelta < 0) ++ilosc;
	if(pNMUpDown->iDelta > 0) --ilosc;
	UpdateData(FALSE);
	*pResult = 0;
}

void CDialogAdd::OnEnChangeEdit3()
{
	UpdateData();
}

void CDialogAdd::OnEnChangeEdit4()
{
	UpdateData();
}

bool same_spacje(CString &niach)
{
	bool same_spacje = true;
	for(int i=0;i<niach.GetLength();i++) if(niach[i] != 32) { same_spacje = false; return same_spacje; }
	return same_spacje;
}

void CDialogAdd::OnBnClickedOk()
{
	UpdateData();
	CString blad("Wykryto b³êdy : \n");
	bool cannot_continue = false;
	if((nazwa.GetLength() == 0) || (same_spacje(nazwa))) { blad += "Nie podano nazwy\n"; cannot_continue = true; }
	if(cena <= 0) { blad += "Niepoprawna cena\n"; cannot_continue = true; }
	if(ilosc <= 0) { blad += "Niepoprawna iloœæ\n"; cannot_continue = true; }
	if(cannot_continue)
	{
		MessageBox(blad,"B³¹d!",MB_ICONERROR);
		return;
	}
	std::vector<unsigned int> indeksy = baza_ref.szukaj(nazwa,cena);
	if((indeksy.size() != 0))
	{
		if(MessageBox("Wykryto, ¿e towar o tej samej nazwie i cenie ju¿ istnieje w bazie.\nCzy chcesz zwiêkszyæ jego iloœæ o zadan¹ wartoœæ?","Pytanko",MB_YESNO | MB_ICONASTERISK) == IDYES)
		{
			towar& tow = baza_ref.zwroc(indeksy[0]);
			for(unsigned int i=0;i<ilosc;++i) ++tow;
			OnOK();
			return;
		}
		else { OnOK(); return; }
	}
	towar nowy(akt_indeks,nazwa,cena,ilosc,komm);
	if(!(baza_ref.dodaj(nowy))) MessageBox("Operacja nie powiod³a siê","B³¹d!",MB_ICONERROR);
	OnOK();
}
