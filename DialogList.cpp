// DialogList.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "DialogList.h"


// CDialogList dialog

IMPLEMENT_DYNAMIC(CDialogList, CDialog)

CDialogList::CDialogList(CWnd* pParent /*=NULL*/,lista &bref)
	: CDialog(CDialogList::IDD, pParent)
	, baza_ref(bref)
{

}

CDialogList::~CDialogList()
{
}

void CDialogList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogList, CDialog)
END_MESSAGE_MAP()

static int CALLBACK sortuj_liste(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* lista = (CListCtrl*) lParamSort;
	int liczba1 = atoi(lista->GetItemText(lParam1,0));
	int liczba2 = atoi(lista->GetItemText(lParam2,0));
	if(liczba1 > liczba2) return -1;
	else if(liczba1 == liczba2) return 0;
	else return 1;
}

BOOL CDialogList::OnInitDialog()
{
	CListCtrl *lista_dlg = new CListCtrl;
	if(lista_dlg == NULL) { MessageBox("Nie uda³o siê utworzyæ listy towarów!","B³¹d",MB_ICONERROR); return FALSE; }
	CRect kwadrat;
	GetClientRect(kwadrat);
	kwadrat.DeflateRect(20,20,20,50);
	lista_dlg->Create(WS_CHILD | WS_VISIBLE | LVS_REPORT,kwadrat,this,1);
	lista_dlg->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lista_dlg->InsertColumn(1,"Indeks",LVCFMT_LEFT,kwadrat.Width()/16);
	lista_dlg->InsertColumn(2,"Nazwa",LVCFMT_LEFT,11*(kwadrat.Width()/16)-15);
	lista_dlg->InsertColumn(3,"Cena",LVCFMT_LEFT,kwadrat.Width()/8);
	lista_dlg->InsertColumn(4,"Iloœæ",LVCFMT_LEFT,kwadrat.Width()/8);
	CString komtekst;
	int item;
	towar temp;
	for(unsigned int i=1;i<=baza_ref.getwielkosc();i++)
	{
		temp = baza_ref.zwroc(i);
		komtekst.Format("%d",temp.getindeks());
		item = lista_dlg->InsertItem(LVIF_TEXT | LVIF_PARAM,1,komtekst,0,0,0,i);
		lista_dlg->SetItemText(item,1,temp.getnazwa());
		komtekst.Format("%.2lf",temp.getcena());
		lista_dlg->SetItemText(item,2,komtekst);
		komtekst.Format("%d",temp.getilosc());
		lista_dlg->SetItemText(item,3,komtekst);
	}
	lista_dlg->SortItems(sortuj_liste,(LPARAM)lista_dlg);
	return TRUE;
}

// CDialogList message handlers
