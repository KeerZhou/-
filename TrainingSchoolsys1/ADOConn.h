// ADOConn.h: interface for the CADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_)
#define AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF1")rename("BOF","adoBOF1")
//���Ӷ�̬��msado15.dll

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CADOConn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);  //ִ��SQL���
	void ExitConnect();                 //�˳����ݿ�����
	void CloseRecordset();              //�رռ�¼��
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);           //ͨ��SQL����ü�¼�� 
	void OnInitADOConn();               //��ʼ�����ݿ�����
	_RecordsetPtr m_pRecordset;         //������¼������
	_ConnectionPtr m_pConnection;       //����һ�����Ӷ���ָ��
	CADOConn();
	virtual ~CADOConn();


};

#endif // !defined(AFX_ADOCONN_H__00E3203D_868E_46A8_8AE1_E9559FFB3C3C__INCLUDED_)
