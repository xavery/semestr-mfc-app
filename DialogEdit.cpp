// DialogEdit.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "DialogEdit.h"


// DialogEdit dialog

IMPLEMENT_DYNAMIC(DialogEdit, CDialog)

DialogEdit::DialogEdit(CWnd* pParent,lista& bref)
	: CDialog(DialogEdit::IDD, pParent)
	, baza_ref(bref)
	, akt_indeks(0)
	, nazwa(_T(""))
	, cena(0)
	, ilosc(0)
	, koment(_T(""))
{

}

DialogEdit::~DialogEdit()
{
}

void DialogEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, akt_indeks);
	DDX_Text(pDX, IDC_EDIT2, nazwa);
	DDX_Text(pDX, IDC_EDIT3, cena);
	DDX_Text(pDX, IDC_EDIT4, ilosc);
	DDX_Text(pDX, IDC_EDIT5, koment);
}


BEGIN_MESSAGE_MAP(DialogEdit, CDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &DialogEdit::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &DialogEdit::OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &DialogEdit::OnDeltaposSpin3)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogEdit::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &DialogEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// DialogEdit message handlers
BOOL DialogEdit::OnInitDialog()
{
	akt_indeks = 1;
	towar temp;
	temp = baza_ref.zwroc(akt_indeks);
	nazwa = temp.getnazwa();
	cena = temp.getcena();
	ilosc = temp.getilosc();
	koment = temp.getkoment();
	UpdateData(FALSE);
	return TRUE;
}

void DialogEdit::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData();
	towar temp = baza_ref.zwroc(akt_indeks);
	if((nazwa != temp.getnazwa()) || (cena != temp.getcena()) || (ilosc != temp.getilosc()) || (koment != temp.getkoment()))
	{
		if(MessageBox("Czy chcesz zapisaæ wprowadzone zmiany?","Smile! :-)",MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			if(akt_indeks == 1) baza_ref.swaptow(towar(akt_indeks,nazwa,cena,ilosc,koment));
			else
			{
				baza_ref.usun(akt_indeks);
				if(!(baza_ref.dodaj(towar(akt_indeks,nazwa,cena,ilosc,koment))))
				{
					MessageBox("Operacja nie powiod³a siê!","B³¹d",MB_ICONERROR);
					return;
				}
			}
		}
	}
	if(pNMUpDown->iDelta < 0)
	{
		if((akt_indeks + 1) > baza_ref.getwielkosc()) return;
		++akt_indeks;
	}
	else
	{
		if((akt_indeks - 1) <= 0) return;
		--akt_indeks;
	}
	temp = baza_ref.zwroc(akt_indeks);
	nazwa = temp.getnazwa();
	cena = temp.getcena();
	ilosc = temp.getilosc();
	koment = temp.getkoment();
	UpdateData(FALSE);
	*pResult = 0;
}

void DialogEdit::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData();
	if(pNMUpDown->iDelta == -1) ++cena;
	else --cena;
	UpdateData(FALSE);
	*pResult = 0;
}

void DialogEdit::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	UpdateData();
	if(pNMUpDown->iDelta == -1) ++ilosc;
	else --ilosc;
	UpdateData(FALSE);
	*pResult = 0;
}

void DialogEdit::OnBnClickedButton1()
{
	if(akt_indeks <= 2)
	{
		MessageBox("Operacja niedozwolona.","B³¹d!",MB_ICONERROR);
		return;
	}
	if(MessageBox("Czy jesteœ pewny, ¿e chcesz usun¹æ ten element?","Hê?! :o",MB_YESNO | MB_ICONQUESTION) == IDNO) return;
	baza_ref.usun(akt_indeks);
	for(unsigned int i=(akt_indeks+1);i<=(baza_ref.getwielkosc()+1);++i) --baza_ref.zwroc(i).modindeks();
	towar temp = baza_ref.zwroc(akt_indeks);
	nazwa = temp.getnazwa();
	cena = temp.getcena();
	ilosc = temp.getilosc();
	koment = temp.getkoment();
	UpdateData(FALSE);
}

void DialogEdit::OnBnClickedOk()
{
	UpdateData();
	towar temp = baza_ref.zwroc(akt_indeks);
	if((nazwa != temp.getnazwa()) || (cena != temp.getcena()) || (ilosc != temp.getilosc()) || (koment != temp.getkoment()))
	{
		if(MessageBox("Czy chcesz zapisaæ wprowadzone zmiany?","Smile! :-)",MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			if(akt_indeks == 1) baza_ref.swaptow(towar(akt_indeks,nazwa,cena,ilosc,koment));
			else
			{
				baza_ref.usun(akt_indeks);
				if(!(baza_ref.dodaj(towar(akt_indeks,nazwa,cena,ilosc,koment))))
				{
					MessageBox("Operacja nie powiod³a siê!","B³¹d",MB_ICONERROR);
					return;
				}
			}
		}
	}
	OnOK();
}
