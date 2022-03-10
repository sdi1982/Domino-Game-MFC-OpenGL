; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COpenGLView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Term_Domino.h"

ClassCount=4
Class1=CTerm_DominoApp
Class2=CTerm_DominoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=COpenGLView
Resource3=IDD_TERM_DOMINO_DIALOG

[CLS:CTerm_DominoApp]
Type=0
HeaderFile=Term_Domino.h
ImplementationFile=Term_Domino.cpp
Filter=N

[CLS:CTerm_DominoDlg]
Type=0
HeaderFile=Term_DominoDlg.h
ImplementationFile=Term_DominoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTerm_DominoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Term_DominoDlg.h
ImplementationFile=Term_DominoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TERM_DOMINO_DIALOG]
Type=1
Class=CTerm_DominoDlg
ControlCount=19
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BLOCK1,button,1342242816
Control5=IDC_BLOCK2,button,1342242816
Control6=IDC_BLOCK3,button,1342242816
Control7=IDC_BLOCK4,button,1342242816
Control8=IDC_BLOCK0,button,1342242816
Control9=IDC_STATIC,static,1342177294
Control10=IDC_STATIC,static,1342177294
Control11=IDC_STATIC,static,1342177294
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_BLOCKTYPE,static,1342308353
Control15=IDC_STAND,button,1342242816
Control16=IDC_RESET,button,1342242816
Control17=IDC_START,button,1342242816
Control18=IDC_EXIT,button,1342242816
Control19=IDC_BOARD,button,1073872903

[CLS:COpenGLView]
Type=0
HeaderFile=OpenGLView.h
ImplementationFile=OpenGLView.cpp
BaseClass=CView
Filter=C
LastObject=COpenGLView
VirtualFilter=VWC

