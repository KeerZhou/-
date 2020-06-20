// ADOConn.cpp: implementation of the CADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CADOConn::CADOConn()
{

}

CADOConn::~CADOConn()
{

}

void CADOConn::OnInitADOConn()        //连接数据库
{
    //初始化OLE/COM库环境
    ::CoInitialize(NULL); 
	 try
	 {
		 //创建connection对象
		 m_pConnection.CreateInstance("ADODB.Connection");    
		 //设置连接字符串
		 m_pConnection->Open("driver={SQL Server};Server=DESKTOP-BFKN1C8;Database=TrainingSchoolSystem;uid=sa;pwd=shenjianyi123;","","",0);
		 //捕捉异常
	 }
	 catch(_com_error e)
	 {
		//显示错误信息
		AfxMessageBox(e.Description());
	 }
}
_RecordsetPtr& CADOConn::GetRecordSet(_bstr_t bstrSQL)       //打开记录集
{
	try
	{
		//连接数据库，如果connection对象为空，则重新连接数据库
		if(m_pConnection==NULL)
			OnInitADOConn();
		//初始化数据库连接
		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//取得表中的记录
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		e.Description();
	}
	//返回记录集
	return m_pRecordset;
}
void CADOConn::CloseRecordset()//关闭记录集
{
	if(m_pRecordset->GetState() == adStateOpen)    //判断当前的记录集状态
		m_pRecordset->Close();       //关闭记录集
}
void CADOConn::ExitConnect()                             //关闭数据库连接
{
	//关闭记录集和连接
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}
BOOL CADOConn::ExecuteSQL(_bstr_t bstrSQL)       //执行SQL语句。用来执行不返回记录集的SQL语句，如inset、Update和Delete
{
	_variant_t RecordsAffected;
	try
	{
		//是否已连接数据库
		if(m_pConnection==NULL)
			OnInitADOConn();
		//connection对象的Execute方法(_bstr_t CommandText,
		//VARIANT * RecordsAffected,long Options)
		//其中CommandText是命令字符串,通常是SQL命令
		//参数RecordsAffected是操作完成后所影响的行数
		//参数Options表示CommandText的类型,adCmdText-文本命令,adCmdTable-表名
		//adCmdStoredProc-存储过程,adCmdUnknown-未知
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}




