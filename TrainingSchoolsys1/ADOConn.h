// ADOConn.h: interface for the CADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_)
#define AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF1")rename("BOF","adoBOF1")
//链接动态库msado15.dll

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CADOConn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);  //执行SQL语句
	void ExitConnect();                 //退出数据库连接
	void CloseRecordset();              //关闭记录集
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);           //通过SQL语句获得记录集 
	void OnInitADOConn();               //初始化数据库连接
	_RecordsetPtr m_pRecordset;         //声明记录集对象
	_ConnectionPtr m_pConnection;       //声明一个连接对象指针
	CADOConn();
	virtual ~CADOConn();


};

#endif // !defined(AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_)
