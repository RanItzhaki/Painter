
// exm2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "exm2.h"
#include "exm2Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cexm2Dlg dialog



Cexm2Dlg::Cexm2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cexm2Dlg::IDD, pParent)

	, colorW(_T(""))
	, int3(0)
	, blue(_T(""))

	, fill(0)
	, nfill(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	isMoves= false;
	isPressed = false;
	curColor = RGB(0, 0, 0);
	lineColor =  RGB(0, 0, 0);
	size = 1;
	Saved = 0;
	Saved2 = 0;
	idx1=0;
	shape = 6;
	idx2 = 0;
	ptCircle = CPoint(0, 0);
	iDiameterY = 0;
	iDiameterX = 0;
	indexm = 0;
	filln = false;
}

void Cexm2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, change1);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colorC);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, colorL);
	DDX_Control(pDX, IDC_COMBO2, change2);

}

BEGIN_MESSAGE_MAP(Cexm2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Cexm2Dlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_BUTTON5, &Cexm2Dlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cexm2Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &Cexm2Dlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &Cexm2Dlg::OnBnClickedMfccolorbutton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cexm2Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexm2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cexm2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cexm2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cexm2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO1, &Cexm2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cexm2Dlg::OnBnClickedRadio2)

END_MESSAGE_MAP()


// Cexm2Dlg message handlers

BOOL Cexm2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cexm2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cexm2Dlg::OnPaint()
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
		CPaintDC dc(this);
		CDialogEx::OnPaint();
	for (int i = 0; i<figs.GetSize(); i++)
		figs[i]->Draw(&dc);

	}
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cexm2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cexm2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	startP = endP = point;
	int x2, y2;
	indexm = figs.GetSize();

	 while (indexm--)
		{
		ptCircle.x = figs[indexm]->x1;
		ptCircle.y = figs[indexm]->y1;

		x2 = figs[indexm]->x2;
		y2 = figs[indexm]->y2;

		iDiameterX = (x2 - ptCircle.x);
		iDiameterY = (y2 - ptCircle.y);


		if (((ptCircle.x <= point.x) && (point.x <= x2)) && ((ptCircle.y >= point.y) && (point.y >= y2)))
		{
			ptCursorOld = point;
			isMoves = true;
			break;
		}
	}

	if (!isMoves)
	{
		isPressed = true;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}




void Cexm2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	endP = point;
	if ((isMoves) && (!filln))
	{
		figs[indexm]->x1 = point.x - iDiameterX / 2;
		figs[indexm]->y1 = point.y - iDiameterY / 2;
		figs[indexm]->x2 = point.x + iDiameterX / 2;
		figs[indexm]->y2 = point.y + iDiameterY / 2;
	}
	else if ((isMoves) && (filln))
	{
		figs[indexm]->curColor = curColor;
		figs[indexm]->lineColor = lineColor;
	}
	if (isPressed)
	{
		if (idx1 == 1)
			figs.Add(new LineM(startP.x, startP.y, endP.x, endP.y, lineColor, size,idx1));
		else if (idx1 == 2)
			figs.Add(new RectangleM(startP.x, startP.y, endP.x, endP.y, curColor, size, lineColor, shape,idx1));
		else if (idx1 == 0)
			figs.Add(new EllipseM(startP.x, startP.y, endP.x, endP.y, curColor, size, lineColor, shape,idx1));
		else if (idx1 == 3)
			figs.Add(new CircleM(startP.x, startP.y, endP.x, endP.y, curColor, size, lineColor, shape, idx1));
		else if (idx1 == 4)
			figs.Add(new TriangleM(startP.x, startP.y, endP.x, endP.y, curColor, size, lineColor, shape, idx1));
	}

	isMoves = false;
	isPressed = false;
	Invalidate();
	CDialogEx::OnLButtonUp(nFlags, point);
}


void Cexm2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{

	if (isPressed)
	{
		CClientDC dc(this);
		CBrush *oldBrush,brush;		 
		brush.CreateHatchBrush(shape, curColor);
		oldBrush = (CBrush*)dc.SelectObject(&brush);
		
		CPen myPen1(PS_SOLID, size, lineColor);
		CPen *oldPen;
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);
		if (idx1 == 2)
		{
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
		}
		else if (idx1 == 1)
		{ 
			dc.MoveTo(startP);
			dc.LineTo(endP.x, endP.y);
			endP = point;
			dc.MoveTo(startP);
			dc.LineTo(endP.x, endP.y);
			
		}
		else if (idx1 == 0)
		{
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
		}
		else if (idx1 == 3)
		{
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
		}
		else if (idx1 == 4)
		{
			dc.MoveTo(startP.x, endP.y);
			dc.LineTo(endP.x, endP.y);
			dc.LineTo((startP.x + endP.x) / 2, startP.y);
			dc.LineTo(startP.x, endP.y);
			endP = point;
			dc.MoveTo(startP.x, endP.y);
			dc.LineTo(endP.x, endP.y);
			dc.LineTo((startP.x + endP.x) / 2, startP.y);
			dc.LineTo(startP.x, endP.y);
		}

		dc.SetROP2(R2_COPYPEN);
	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void Cexm2Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{


	CDialogEx::OnRButtonUp(nFlags, point);
}


void Cexm2Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{

		CDialogEx::OnRButtonDown(nFlags, point);
	
}


//slider
void Cexm2Dlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	CSliderCtrl* SizeB = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	SizeB->SetRange(1, 9);
	int nControl = SizeB->GetDlgCtrlID();
	CSliderCtrl* pControl = (CSliderCtrl*)GetDlgItem(nControl);
	size = pControl->GetPos();

	UpdateData(true);
	int3 = size;
	UpdateData(false);
	*pResult = 0;
}



//shape change
void Cexm2Dlg::OnCbnSelchangeCombo1()
{

	idx1 = change1.GetCurSel();
	UpdateData(true);
	UpdateData(false);
		
	// TODO: Add your control notification handler code here
}


void Cexm2Dlg::OnBnClickedMfccolorbutton1()
{
	
	curColor = colorC.GetColor();
	// TODO: Add your control notification handler code here
}


void Cexm2Dlg::OnBnClickedMfccolorbutton2()
{
	lineColor = colorL.GetColor();
}

//shape lines
void Cexm2Dlg::OnCbnSelchangeCombo2()
{
	idx2 = change2.GetCurSel();
	if (idx2 == 0)
		shape = 6;
	else if (idx2 == 1)
		shape = 0;
	else if (idx2 == 2)
		shape = 1;
	else if (idx2 == 3)
		shape = 2;
	else if (idx2 == 4)
		shape = 3;
	else if (idx2 == 5)
		shape = 4;
	// TODO: Add your control notification handler code here
}


void Cexm2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void Cexm2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();

	UpdateData(true);
	UpdateData(false);
}


void Cexm2Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
	UpdateData(true);
	UpdateData(false);
}

//undo
void Cexm2Dlg::OnBnClickedButton4()
{
	int dx = figsB.GetSize() - 1;
	int nn = figsB[dx]->idxN;

	if (nn == 1)
		figs.Add(new LineM(figsB[dx]->x1, figsB[dx]->y1, figsB[dx]->x2, figsB[dx]->y2, figsB[dx]->lineColor, figsB[dx]->x, nn));
	else if (nn == 2)
		figs.Add(new RectangleM(figsB[dx]->x1, figsB[dx]->y1, figsB[dx]->x2, figsB[dx]->y2, figsB[dx]->curColor, figsB[dx]->x, figsB[dx]->lineColor, figsB[dx]->s, nn));
	else if (nn == 0)
		figs.Add(new EllipseM(figsB[dx]->x1, figsB[dx]->y1, figsB[dx]->x2, figsB[dx]->y2, figsB[dx]->curColor, figsB[dx]->x, figsB[dx]->lineColor, figsB[dx]->s, nn));
	else if (nn == 3)
		figs.Add(new CircleM(figsB[dx]->x1, figsB[dx]->y1, figsB[dx]->x2, figsB[dx]->y2, figsB[dx]->curColor, figsB[dx]->x, figsB[dx]->lineColor, figsB[dx]->s, nn));
	else if (nn == 4)
		figs.Add(new TriangleM(figsB[dx]->x1, figsB[dx]->y1, figsB[dx]->x2, figsB[dx]->y2, figsB[dx]->curColor, figsB[dx]->x, figsB[dx]->lineColor, figsB[dx]->s, nn));

	figsB.RemoveAt(figsB.GetSize() - 1, 1);

	UpdateData(true);
	UpdateData(false);

	Invalidate();
}


//erase last
void Cexm2Dlg::OnBnClickedButton5()
{
	int dx = figs.GetSize() - 1;
	int nn = figs[dx]->idxN;
	
	if (nn == 1)
		figsB.Add(new LineM(figs[dx]->x1, figs[dx]->y1, figs[dx]->x2, figs[dx]->y2, figs[dx]->lineColor, figs[dx]->x, nn));
	else if (nn == 2)
		figsB.Add(new RectangleM(figs[dx]->x1, figs[dx]->y1, figs[dx]->x2, figs[dx]->y2, figs[dx]->curColor, figs[dx]->x, figs[dx]->lineColor, figs[dx]->s, nn));
	else if (nn == 0)
		figsB.Add(new EllipseM(figs[dx]->x1, figs[dx]->y1, figs[dx]->x2, figs[dx]->y2, figs[dx]->curColor, figs[dx]->x, figs[dx]->lineColor, figs[dx]->s, nn));
	else if (nn == 3)
		figsB.Add(new CircleM(figs[dx]->x1, figs[dx]->y1, figs[dx]->x2, figs[dx]->y2, figs[dx]->curColor, figs[dx]->x, figs[dx]->lineColor, figs[dx]->s, nn));
	else if (nn == 4)
		figsB.Add(new TriangleM(figs[dx]->x1, figs[dx]->y1, figs[dx]->x2, figs[dx]->y2, figs[dx]->curColor, figs[dx]->x, figs[dx]->lineColor, figs[dx]->s, nn));

	figs.RemoveAt(figs.GetSize() - 1, 1);

	UpdateData(true);
	UpdateData(false);

	Invalidate();
}


void Cexm2Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	filln = false;
	
}


void Cexm2Dlg::OnBnClickedRadio2()
{
	filln = true;
	
	// TODO: Add your control notification handler code here
}
