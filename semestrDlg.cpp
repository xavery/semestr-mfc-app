
// semestrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "semestr.h"
#include "semestrDlg.h"
#include "DialogAdd.h"
#include "DialogList.h"
#include "DialogEdit.h"
#include "DialogSearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CsemestrDlg dialog




CsemestrDlg::CsemestrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CsemestrDlg::IDD, pParent)
	, ile_w_bazie(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsemestrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ile_w_bazie);
}

BEGIN_MESSAGE_MAP(CsemestrDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CsemestrDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CsemestrDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CsemestrDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &CsemestrDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON5, &CsemestrDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDCANCEL, &CsemestrDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CsemestrDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CsemestrDlg message handlers

BOOL CsemestrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CsemestrDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CsemestrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CsemestrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CsemestrDlg::OnBnClickedButton1()
{
	CDialogAdd okno_dodaj(this,baza);
	okno_dodaj.DoModal();
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
}

void CsemestrDlg::OnBnClickedButton2()
{
	if(baza.getwielkosc() == 0) { MessageBox("Baza jest pusta!","B³¹d",MB_ICONERROR); return; }
	DialogEdit okno_edytuj(this,baza);
	okno_edytuj.DoModal();
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
}

void CsemestrDlg::OnBnClickedButton3()
{
	if(baza.getwielkosc() == 0) { MessageBox("Baza jest pusta!","B³¹d",MB_ICONERROR); return; }
	CDialogList okno_listy(this,baza);
	okno_listy.DoModal();
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
}

void CsemestrDlg::OnBnClickedButton8()
{
	if(baza.getwielkosc() == 0)
	{
		MessageBox("Baza jest pusta!","B³¹d",MB_ICONERROR);
		return;
	}
	CFileDialog okno_zapisz(FALSE,"aze","*.aze");
	if(okno_zapisz.DoModal() != IDOK) return;
	std::ofstream plik;
	plik.open(okno_zapisz.GetPathName(),std::ios::out);
	plik << baza;
	plik.close();
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
}

void CsemestrDlg::OnBnClickedButton5()
{
	if(baza.getwielkosc() != 0)
	{
		if(MessageBox("Wczytanie bazy z pliku nadmieni ca³¹ jej dotychczasow¹ zawartoœæ!\nCzy siê zgadzasz?","Uwaga!",MB_YESNO | MB_ICONWARNING) == IDNO) return;
		baza.implode();
	}
	CFileDialog okno_otworz(TRUE,"aze","*.aze");
	if(okno_otworz.DoModal() != IDOK) return;
	std::ifstream plik;
	plik.open(okno_otworz.GetPathName(),std::ios::in);
	try { plik >> baza; }
	catch (char* wiadomosc) { MessageBox(CString(wiadomosc),"B³¹d!",MB_ICONERROR); }
	plik.close();
	ile_w_bazie = baza.getwielkosc();
	UpdateData(FALSE);
}
void CsemestrDlg::OnBnClickedCancel()
{
	baza.implode();
	OnCancel();
}

void CsemestrDlg::OnBnClickedButton4()
{
	if(baza.getwielkosc() == 0)
	{
		MessageBox("Baza jest pusta!","B³¹d",MB_ICONERROR);
		return;
	}
	CDialogSearch okno_szukaj(this,baza);
	okno_szukaj.DoModal();
}
