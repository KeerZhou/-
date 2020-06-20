# Microsoft Developer Studio Project File - Name="TrainingSchoolsys" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TrainingSchoolsys - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TrainingSchoolsys.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TrainingSchoolsys.mak" CFG="TrainingSchoolsys - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TrainingSchoolsys - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TrainingSchoolsys - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TrainingSchoolsys - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TrainingSchoolsys - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TrainingSchoolsys - Win32 Release"
# Name "TrainingSchoolsys - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddSubjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddSubjectDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckMessageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CurrentSituationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeleteMySubjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeleteSubjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DIALOG_STUDENT.cpp
# End Source File
# Begin Source File

SOURCE=.\DIALOG_TEACHER.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_login.cpp
# End Source File
# Begin Source File

SOURCE=.\LeaveMessageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTimeTableDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Pay.cpp
# End Source File
# Begin Source File

SOURCE=.\PersonalINFODlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReplyMessageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendReplyMessageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowAllSubjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowAllSubjectDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SubjectINFODlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TrainingSchoolsys.cpp
# End Source File
# Begin Source File

SOURCE=.\TrainingSchoolsys.rc
# End Source File
# Begin Source File

SOURCE=.\TrainingSchoolsysDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UserINFODlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddSubjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddSubjectDlg1.h
# End Source File
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\CheckMessageDlg.h
# End Source File
# Begin Source File

SOURCE=.\CurrentSituationDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeleteMySubjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeleteSubjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\DIALOG_STUDENT.h
# End Source File
# Begin Source File

SOURCE=.\DIALOG_TEACHER.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_login.h
# End Source File
# Begin Source File

SOURCE=.\LeaveMessageDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyTimeTableDlg.h
# End Source File
# Begin Source File

SOURCE=.\Pay.h
# End Source File
# Begin Source File

SOURCE=.\PersonalINFODlg.h
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.h
# End Source File
# Begin Source File

SOURCE=.\ReplyMessageDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SendReplyMessageDlg.h
# End Source File
# Begin Source File

SOURCE=.\ShowAllSubjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\ShowAllSubjectDlg1.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SubjectINFODlg.h
# End Source File
# Begin Source File

SOURCE=.\TrainingSchoolsys.h
# End Source File
# Begin Source File

SOURCE=.\TrainingSchoolsysDlg.h
# End Source File
# Begin Source File

SOURCE=.\UserINFODlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\TrainingSchoolsys.ico
# End Source File
# Begin Source File

SOURCE=.\res\TrainingSchoolsys.rc2
# End Source File
# Begin Source File

SOURCE=".\res\±³¾°.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\¶þÎ¬Âë.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
