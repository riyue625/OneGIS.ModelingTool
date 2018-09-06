//***************************************************************************************
// FileName��IVBF_Message.h
// Function����Ϣ��Ӧ�ӿڡ�
//           ÿ����������Ҫ��Ӧ���������������Ϣ����Ҫʵ�ָýӿڡ�
// Author:   �����
// Date:     2006-4-22
//***************************************************************************************

#ifndef __IVBF_MESSAGE_H__
#define __IVBF_MESSAGE_H__


class IVBF_Message
{
public:
	virtual ~IVBF_Message() {}

public:

	//---------------------------------------------------------------
	// GetMessageCount:��ȡ�������Ӧ����Ϣ����
	// return �����Ӧ����Ϣ����
	//---------------------------------------------------------------
	virtual int GetMessageCount() = 0;

	//---------------------------------------------------------------
	// ��ȡָ����ϢID��������޹ء�
	// nIndex ����ϢID�����ţ����ڱ���������Ϣ��
	// return ��ϢID��
	//---------------------------------------------------------------
	virtual const char* GetMessageID(int nIndex) = 0;

	//---------------------------------------------------------------
	// OnMessage:��Ӧ��Ϣ��
	// szMessage ����ϢID��
	// nValue��pValue ����Ϣ�Ĳ��������庬������Ϣ����������
	//---------------------------------------------------------------
	virtual void OnMessage(void* pSender,const char* szMessage, int nValue, void* pValue) = 0;

	//---------------------------------------------------------------
	// ������Ϣ (��Ө���ӣ�2006-5-8)
	//---------------------------------------------------------------
	virtual void SubscribeMessage() = 0;
};

#endif