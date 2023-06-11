// DialogSearch.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "DialogSearch.h"
#include "DialogShow.h"

// CDialogSearch dialog

IMPLEMENT_DYNAMIC(CDialogSearch, CDialog)

CDialogSearch::CDialogSearch(CWnd* pParent,lista& bref)
	: CDialog(CDialogSearch::IDD, pParent)
	, nazwa(_T(""))
	, uzyj_nazwy(FALSE)
	, uzyj_ceny(FALSE)
	, uzyj_ilosci(FALSE)
	, czy_zakres_ceny(FALSE)
	, czy_zakres_ilosci(FALSE)
	, cena(0)
	, cena_lo(0)
	, cena_hi(0)
	, ilosc(0)
	, ilosc_lo(0)
	, ilosc_hi(0)
	, baza_ref(bref)
{

}

CDialogSearch::~CDialogSearch()
{
}

void CDialogSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, nazwa);
	DDX_Check(pDX, IDC_CHECK1, uzyj_nazwy);
	DDX_Check(pDX, IDC_CHECK2, uzyj_ceny);
	DDX_Check(pDX, IDC_CHECK3, uzyj_ilosci);
	DDX_Radio(pDX, IDC_RADIO1, czy_zakres_ceny);
	DDX_Radio(pDX, IDC_RADIO3, czy_zakres_ilosci);
	DDX_Text(pDX, IDC_EDIT2, cena);
	DDX_Text(pDX, IDC_EDIT3, cena_lo);
	DDX_Text(pDX, IDC_EDIT6, cena_hi);
	DDX_Text(pDX, IDC_EDIT4, ilosc);
	DDX_Text(pDX, IDC_EDIT7, ilosc_lo);
	DDX_Text(pDX, IDC_EDIT8, ilosc_hi);
}


BEGIN_MESSAGE_MAP(CDialogSearch, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CDialogSearch::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDialogSearch::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDialogSearch::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_RADIO1, &CDialogSearch::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDialogSearch::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDialogSearch::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDialogSearch::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogSearch::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialogSearch message handlers

void CDialogSearch::OnBnClickedCheck1()
{
	UpdateData();
	if(uzyj_nazwy) GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	else GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
}

void CDialogSearch::OnBnClickedCheck2()
{
	UpdateData();
	if(uzyj_ceny)
	{
		GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	}
}

void CDialogSearch::OnBnClickedCheck3()
{
	UpdateData();
	if(uzyj_ilosci)
	{
		GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
	}
}

void CDialogSearch::OnBnClickedRadio1()
{
	UpdateData();
	if(!uzyj_ceny) return;
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
}

void CDialogSearch::OnBnClickedRadio2()
{
	UpdateData();
	if(!uzyj_ceny) return;
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
}

void CDialogSearch::OnBnClickedRadio3()
{
	UpdateData();
	if(!uzyj_ilosci) return;
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
}

void CDialogSearch::OnBnClickedRadio4()
{
	UpdateData();
	if(!uzyj_ilosci) return;
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT8)->EnableWindow(TRUE);
}

BOOL CDialogSearch::OnInitDialog()
{
	uzyj_nazwy = 1;
	uzyj_ceny = 1;
	uzyj_ilosci = 1;
	czy_zakres_ceny = 0;
	czy_zakres_ilosci = 0;
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
	UpdateData(FALSE);
	return TRUE;
}
void CDialogSearch::OnBnClickedButton1()
{
	UpdateData();
	bool cannot_continue = false;
	CString bledy("Wyst¹pi³y b³êdy : \n");
	if((uzyj_nazwy) && (nazwa.GetLength() == 0))
	{
		bledy += "Niepoprawnie wpisana nazwa\n";
		cannot_continue = true;
	}
	if((uzyj_ceny) && (czy_zakres_ceny) && ((cena_hi <= 0) || (cena_lo <= 0)))
	{
		bledy += "Niepoprawnie wpisany zakres ceny\n";
		cannot_continue = true;
	}
	if((uzyj_ceny) && (!czy_zakres_ceny) && (cena <= 0))
	{
		bledy += "Niepoprawnie wpisana cena\n";
		cannot_continue = true;
	}
	if((uzyj_ilosci) && (czy_zakres_ilosci) && ((ilosc_hi <= 0) || (ilosc_lo <= 0)))
	{
		bledy += "Niepoprawnie wpisany zakres iloœci\n";
		cannot_continue = true;
	}
	if((uzyj_ilosci) && (!czy_zakres_ilosci) && (ilosc <= 0))
	{
		bledy += "Niepoprawnie wpisana iloœæ\n";
		cannot_continue = true;
	}
	if(cannot_continue)
	{
		MessageBox(bledy,"Booo! :(",MB_ICONERROR);
		return;
	}
	std::vector<unsigned int> indeksy;
	if(uzyj_nazwy)
	{
		if((uzyj_ceny) && (uzyj_ilosci))
		{
			if((czy_zakres_ceny) && (czy_zakres_ilosci))
			{
				indeksy = baza_ref.szukaj(nazwa,cena_lo,cena_hi,ilosc_lo,ilosc_hi);
			}
			else if((czy_zakres_ilosci) && (!czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(nazwa,cena,ilosc_lo,ilosc_hi);
			}
			else if((!czy_zakres_ilosci) && (czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(nazwa,cena_lo,cena_hi,ilosc);
			}
			else if((!czy_zakres_ilosci) && (!czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(nazwa,cena,ilosc);
			}
		}
		else if((uzyj_ceny) && (!uzyj_ilosci))
		{
			if(czy_zakres_ceny)
			{
				indeksy = baza_ref.szukaj(nazwa,cena_lo,cena_hi);
			}
			else
			{
				indeksy = baza_ref.szukaj(nazwa,cena);
			}
		}
		else if((!uzyj_ceny) && (uzyj_ilosci))
		{
			if(czy_zakres_ilosci)
			{
				indeksy = baza_ref.szukaj(nazwa,ilosc_lo,ilosc_hi);
			}
			else
			{
				indeksy = baza_ref.szukaj(nazwa,ilosc);
			}
		}
		else if((!uzyj_ceny) && (!uzyj_ilosci))
		{
			indeksy = baza_ref.szukaj(nazwa);
		}
	}
	else
	{
		if((uzyj_ceny) && (uzyj_ilosci))
		{
			if((czy_zakres_ceny) && (czy_zakres_ilosci))
			{
				indeksy = baza_ref.szukaj(cena_lo,cena_hi,ilosc_lo,ilosc_hi);
			}
			else if((czy_zakres_ilosci) && (!czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(cena,ilosc_lo,ilosc_hi);
			}
			else if((!czy_zakres_ilosci) && (czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(cena_lo,cena_hi,ilosc);
			}
			else if((!czy_zakres_ilosci) && (!czy_zakres_ceny))
			{
				indeksy = baza_ref.szukaj(cena,ilosc);
			}
		}
		else if((uzyj_ceny) && (!uzyj_ilosci))
		{
			if(czy_zakres_ceny)
			{
				indeksy = baza_ref.szukaj(cena_lo,cena_hi);
			}
			else
			{
				indeksy = baza_ref.szukaj(cena);
			}
		}
		else if((!uzyj_ceny) && (uzyj_ilosci))
		{
			if(czy_zakres_ilosci)
			{
				indeksy = baza_ref.szukaj(ilosc_lo,ilosc_hi);
			}
			else
			{
				indeksy = baza_ref.szukaj(ilosc);
			}
		}
		else if((!uzyj_ceny) && (!uzyj_ilosci))
		{
			MessageBox("Proszê wybraæ co najmniej jedno z kryteriów.",":P",MB_ICONASTERISK);
			return;
		}
	}
	if(indeksy.size() == 0)
	{
		MessageBox("Wyszukiwanie nie zwróci³o ¿adnych rezultatów.","ojejku jej",MB_ICONASTERISK);
		return;
	}
	CDialogShow okno_pokaz(this,baza_ref,indeksy);
	okno_pokaz.DoModal();
}
