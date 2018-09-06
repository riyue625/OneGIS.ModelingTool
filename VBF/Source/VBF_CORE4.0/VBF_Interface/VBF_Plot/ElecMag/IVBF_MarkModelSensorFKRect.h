//*******************************************************************
// FileName��IVBF_MarkModelSensorFKRect.h
// Function�������״������Ϊ���Σ�
// Author:   ��Ө
// Date:    2013-11-01
//*******************************************************************

#ifndef __IVBF_MARK_MODEL_SENSOR_FK_RECT_H__
#define __IVBF_MARK_MODEL_SENSOR_FK_RECT_H__


#include "IVBF_MarkModelSensor.h"
#include <VBF_Plot/ElecMag/IVBF_MarkModelSensorRect.h>
#include <VBF_Plot/ElecMag/IVBF_MarkModelSensorDome.h>


class IVBF_MarkModelSensorFKRect : public IVBF_MarkModelSensor
{
public:
    virtual ~IVBF_MarkModelSensorFKRect() {}

    // ��ȡ�������еĸ�����״�ӿڣ��Ա������뼸����״�йصĲ���
    virtual IVBF_MarkModelSensorRect* GetSensorRect()=0;	// ������������ƽ��ͷ�壩
    virtual IVBF_MarkModelSensorDome* GetDetectZone()=0;	// ̽������Բ���Σ�

	// ����/�ر�ɨ�裨Ĭ��Ϊ������
	virtual void EnableScan(bool bEnable)=0;
	virtual bool IsScanEnabled()=0;

	// ����/��ȡɨ���ٶȣ���λ���Ƕ�/�룬Ĭ��ֵΪ2.0��
	virtual void  SetScanSpeed(float fSpeed)=0;
	virtual float GetScanSpeed()=0;
};

#endif 