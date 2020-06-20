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

void CADOConn::OnInitADOConn()        //�������ݿ�
{
    //��ʼ��OLE/COM�⻷��
    ::CoInitialize(NULL); 
	 try
	 {
		 //����connection����
		 m_pConnection.CreateInstance("ADODB.Connection");    
		 //���������ַ���
		 m_pConnection->Open("driver={SQL Server};Server=DESKTOP-BFKN1C8;Database=TrainingSchoolSystem;uid=sa;pwd=shenjianyi123;","","",0);
		 //��׽�쳣
	 }
	 catch(_com_error e)
	 {
		//��ʾ������Ϣ
		AfxMessageBox(e.Description());
	 }
}
_RecordsetPtr& CADOConn::GetRecordSet(_bstr_t bstrSQL)       //�򿪼�¼��
{
	try
	{
		//�������ݿ⣬���connection����Ϊ�գ��������������ݿ�
		if(m_pConnection==NULL)
			OnInitADOConn();
		//��ʼ�����ݿ�����
		//������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		e.Description();
	}
	//���ؼ�¼��
	return m_pRecordset;
}
void CADOConn::CloseRecordset()//�رռ�¼��
{
	if(m_pRecordset->GetState() == adStateOpen)    //�жϵ�ǰ�ļ�¼��״̬
		m_pRecordset->Close();       //�رռ�¼��
}
void CADOConn::ExitConnect()                             //�ر����ݿ�����
{
	//�رռ�¼��������
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}
BOOL CADOConn::ExecuteSQL(_bstr_t bstrSQL)       //ִ��SQL��䡣����ִ�в����ؼ�¼����SQL��䣬��inset��Update��Delete
{
	_variant_t RecordsAffected;
	try
	{
		//�Ƿ����������ݿ�
		if(m_pConnection==NULL)
			OnInitADOConn();
		//connection�����Execute����(_bstr_t CommandText,
		//VARIANT * RecordsAffected,long Options)
		//����CommandText�������ַ���,ͨ����SQL����
		//����RecordsAffected�ǲ�����ɺ���Ӱ�������
		//����Options��ʾCommandText������,adCmdText-�ı�����,adCmdTable-����
		//adCmdStoredProc-�洢����,adCmdUnknown-δ֪
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}




