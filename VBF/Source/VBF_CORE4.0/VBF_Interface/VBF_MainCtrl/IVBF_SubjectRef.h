//***************************************************************************************
// FileName��IVBF_SubjectRef.h
// Function�����۲��߽ӿ�
//           Observerģʽ�е� ���۲��ߣ�Subject���ӿڡ�
// Author:   �����
// Date:     2006-4-22
//***************************************************************************************

#ifndef __IVBF_SUBJECT_REF_H__
#define __IVBF_SUBJECT_REF_H__

#include <VBF_Base/VBF_Referenced.h>
class IVBF_ObserverRef;


class IVBF_SubjectRef : public CVBF_Referenced
{
public:
    virtual ~IVBF_SubjectRef() {}

public:

	//---------------------------------------------------------------
	//  Attach:���ӹ۲���
	//  ��ָ���Ĺ۲��߶������ӵ���Ӧ����Ϣ��Ӧ�б��С�
	//  pObserver�������ӵĹ۲��߶���ָ��
	//---------------------------------------------------------------
    virtual void Attach(IVBF_ObserverRef* pIObserver) = 0;

	//---------------------------------------------------------------
	// Detach:ȡ���۲���
	// ��ָ���Ĺ۲��߶����ָ����Ϣ��Ӧ�б���ɾ����
	// pObserver����ɾ���Ĺ۲��߶���ָ��
	//---------------------------------------------------------------
    virtual void Detach(IVBF_ObserverRef* pIObserver) = 0;

 	//---------------------------------------------------------------
    // DetachAll:ȡ�����й۲���
	// �����й۲��ߴ�������Ϣ��Ӧ�б��С�
 	//---------------------------------------------------------------
    virtual void DetachAll() = 0;

 	//---------------------------------------------------------------
	// Notify:������Ϣ 
	// ��ָ����Ϣ���͸���Ӧ�Ĺ۲��ߡ�
	// szMessage��Ҫ���͵���Ϣ��
	// iValue����Ϣ������������
	// pValue����Ϣ��ָ�������
 	//---------------------------------------------------------------
    virtual void Notify(const char* szMessage, int nValue=0, void* pValue=NULL) = 0;
};

#endif