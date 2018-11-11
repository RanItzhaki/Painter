
// exm2Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Figure.h"
#include "afxcolorbutton.h"

// Cexm2Dlg dialog
class Cexm2Dlg : public CDialogEx
{

	CTypedPtrArray< CObArray, Figure*> figs;
	CTypedPtrArray< CObArray, Figure*> figsB;
// Construction
	enum FIGURES{ RECTANGLE, ELLIPSE, LINE, CIRCLE, TRIANGLE };	
	
public:
	Cexm2Dlg(CWnd* pParent = NULL);	// standard constructor

	int size;
	int Saved;
	int Saved2;
	int indexm;
	COLORREF curColor;
	COLORREF lineColor;
	int shape;
	bool filln;
	int idx2;
	int iDiameterY;
	int iDiameterX;
	CPoint ptCircle;
	CPoint ptCursorOld;
// Dialog Data
	enum { IDD = IDD_EXM2_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:

	HICON m_hIcon;
	bool isMoves;
	bool isPressed;
	CPoint startP, endP;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CString colorW;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnBnClickedButton5();
	int int3;
	int idx1;
	CString blue;
	
	CComboBox ggg;
	CComboBox change1;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedMfccolorbutton1();
	CMFCColorButton colorC;
	CMFCColorButton colorL;
	afx_msg void OnBnClickedMfccolorbutton2();
	CComboBox change2;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	int fill;
	int nfill;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	
};
