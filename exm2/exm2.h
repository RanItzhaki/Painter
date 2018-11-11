
// exm2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cexm2App:
// See exm2.cpp for the implementation of this class
//

class Cexm2App : public CWinApp
{
public:
	Cexm2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cexm2App theApp;