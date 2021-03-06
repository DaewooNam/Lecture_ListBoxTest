
// ListBoxTestDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ListBoxTest.h"
#include "ListBoxTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListBoxTestDlg 대화 상자



CListBoxTestDlg::CListBoxTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTBOXTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_GENERAL2, m_listbox);
	DDX_Control(pDX, IDC_LIST_NOSORT, m_listbox_noSort); // 변수면이 헷갈리시 ctrl + " "
	DDX_Control(pDX, IDC_LIST_INPUT, m_listbox_Input);



	DDX_Text(pDX, IDC_EDIT_INPUT, m_strEditInput);
	DDX_Text(pDX, IDC_EDIT_FIND, m_strEditFind);
	

}

BEGIN_MESSAGE_MAP(CListBoxTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST_GENERAL2, &CListBoxTestDlg::OnLbnSelchangeListGeneral2)
	ON_LBN_DBLCLK(IDC_LIST_GENERAL2, &CListBoxTestDlg::OnLbnDblclkListGeneral2)
	ON_BN_CLICKED(IDC_BUTTON1, &CListBoxTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListBoxTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CListBoxTestDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CListBoxTestDlg 메시지 처리기

BOOL CListBoxTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.



	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	

	m_listbox.AddString("c/c++");
	m_listbox.AddString("java");
	m_listbox.AddString("unity");
	m_listbox.AddString("android");
	m_listbox.AddString("c#");
	m_listbox.AddString("oracle");
	m_listbox.AddString("database");
	m_listbox.AddString("directx");
	m_listbox.InsertString(0, "zzzzzzzzzz12312312312@@"); // 맨 위로 넣어 줗
	m_listbox.SetHorizontalExtent(500);
	

	int selidx = m_listbox.FindString(-1,"c#"); // 기존의 값이 있는지 없는지 확인
	
	if (selidx != LB_ERR)
		m_listbox.SetCurSel(selidx);
	else
		m_listbox.AddString("c#");
		



	m_listbox_noSort.AddString("c/c++");
	m_listbox_noSort.AddString("java");
	m_listbox_noSort.AddString("unity");
	m_listbox_noSort.AddString("android");
	m_listbox_noSort.AddString("c#");
	m_listbox_noSort.AddString("oracle");
	m_listbox_noSort.AddString("database");
	m_listbox_noSort.AddString("directx");




	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListBoxTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CListBoxTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CListBoxTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBoxTestDlg::OnLbnSelchangeListGeneral2()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE("OnLbnSelchangeListGeneral2()\n");

	

}


void CListBoxTestDlg::OnLbnDblclkListGeneral2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE("OnLbnDblclkListGeneral2()\n");

	int nIdx = m_listbox.GetCurSel(); //index 값 받기

	TRACE("OnLbnDblclkListGeneral2() : %d\n",nIdx);

	m_listbox.DeleteString(nIdx); // 값 삭제



}


void CListBoxTestDlg::OnBnClickedButton1() //추가
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(true);
	
	m_listbox_Input.InsertString(0, m_strEditInput);

}


void CListBoxTestDlg::OnBnClickedButton2() //검색1
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	int nSelIndex = m_listbox_Input.FindString(-1, m_strEditFind);

	CString str = "찾기 결과 : 없음";

	if (nSelIndex != LB_ERR) //찾음
	{
		CString tmp;
		m_listbox_Input.GetText(nSelIndex,tmp);
		m_listbox_Input.SetCurSel(nSelIndex);
		TRACE(tmp);
	}

}


void CListBoxTestDlg::OnBnClickedButton3() //검색2
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	int nSelIndex = m_listbox_Input.FindStringExact(-1, m_strEditFind);

	CString str = "찾기 결과 : 없음";

	if (nSelIndex != LB_ERR) //찾음
	{
		CString tmp;
		m_listbox_Input.GetText(nSelIndex, tmp);
		m_listbox_Input.SetCurSel(nSelIndex);
		TRACE(tmp);
	}

}
