//*******************************************************************
// FileName��IVBF_MarkModelCoordSys.h
// Function��ʵ��ģ�ͽӿڣ�����ϵ
// Author:   ��Ө
// Date:     2017-04-05
//*******************************************************************

#ifndef __IVBF_MARK_MODEL_COORDSYS_H__
#define __IVBF_MARK_MODEL_COORDSYS_H__


#include <VBF_Plot/IVBF_MarkModelPoint.h>
#include <Types/VBF_3DStyles.h>
#include <VBF_Plot/Common/VBF_3DPlotDataTypes_Common.h>
#include <Types/Vec3d>
#include <Types/Vec4f>
#include <vector>

namespace VBF
{
    //------------------------------------------------------
    // ����ö�٣�COORDSTYLE
    // ö������������ϵ����ʽ
    //------------------------------------------------------
    enum COORDSTYLE
    {
        NOCOORD,        // ����ʾ����ϵ
        BOX,            // ��״����ϵ��������ģ�͵İ�Χ�У�Ĭ��ֵ��
        FRAME           // ���״����ϵ��ֻ��3����
    };

    //------------------------------------------------------
    // ����ö�٣�AXIS
    // ö����������״����ϵ��12���ᣨ����Χ�е�12���ߣ�
    //------------------------------------------------------
    enum AXIS
    {
        X1 = 0,
        X2 = 3,
        X3 = 4,
        X4 = 5,
        Y1 = 1,
        Y2 = 8,
        Y3 = 7,
        Y4 = 6,
        Z1 = 2,
        Z2 = 9,
        Z3 = 11,
        Z4 = 10
    };

    //------------------------------------------------------
    // ����ö�٣�SIDE
    // ö����������״����ϵ��6����
    //------------------------------------------------------
    enum SIDE
    {
        NOSIDEGRID = 0,
        LEFT   = 1 << 0,
        RIGHT  = 1 << 1,
        CEIL   = 1 << 2,
        FLOOR  = 1 << 3,
        FRONT  = 1 << 4,
        BACK   = 1 << 5
    };

    //------------------------------------------------------
    // ����ö�٣�SCALETYPE
    // ö���������������ϵĿ̶ȷ�ʽ
    //------------------------------------------------------
    enum SCALETYPE
    {
        LINEARSCALE,    // ���Կ̶ȣ�Ĭ��ֵ��
        LOG10SCALE,     // log10
        USERSCALE       // �û��Զ���Ŀ̶�
    };

    //------------------------------------------------------
    // ����ö�٣�ANCHOR
    // ö����������ǩ�ȵĶ�λ��ʽ
    //------------------------------------------------------
    enum ANCHOR
    {
        BottomLeft,
        BottomRight,
        BottomCenter,
        TopLeft,
        TopRight,
        TopCenter,
        CenterLeft,
        CenterRight,
        Center
    };

    //------------------------------------------------------
    // ����ö�٣�FONTWEIGHT
    // ö������������ļӴ���ʽ
    //------------------------------------------------------
    enum FONTWEIGHT
    {
        Light    = 25,
        Normal   = 50,
        DemiBold = 63,
        Bold     = 75,
        Black    = 87
    };
}


class IVBF_MarkModelCoordSys : public IVBF_MarkModelPoint
{
public:
    virtual ~IVBF_MarkModelCoordSys() {}

    // ����/��ȡ����ϵ����ʽ��Ĭ��ΪBOX��
    virtual void SetStyle(VBF::COORDSTYLE s, VBF::AXIS frame1=VBF::X1, VBF::AXIS frame2=VBF::Y1, VBF::AXIS frame3=VBF::Z1)=0;
    virtual VBF::COORDSTYLE GetStyle() const=0;

    // ����/��ȡ����ϵ�̶�ֵ��Χ�Ƿ�Ӹ�ģ�Ͱ�Χ�л�ȡ��Ĭ��Ϊtrue�����Ϊfalse���û���Ҫ����SetPostion()������
    virtual void SetPositionFromParent(bool bFromParent)=0;
    virtual bool IsPositionFromParent()=0;

    // ����/��ȡ����ϵ��xyz�̶�ֵ��Χ������first��second�ֱ��ʾ��С�̶�ֵ�����̶�ֵ���ڴ�
    virtual void SetPosition(osg::Vec3d first, osg::Vec3d second)=0;
    virtual osg::Vec3d  GetPositionFirst()=0;
    virtual osg::Vec3d  GetPositionSecond()=0;


    //========================= ���º���������������������Ĺ�ͬ���� ================================

    // �����������������ɫ��Ĭ��Ϊ��ɫ��
    virtual void	   SetAxesColor(const osg::Vec4f& val)=0;
	virtual osg::Vec4f GetAxesColor()=0;

    // ��������������̶�ֵ�����壨Ĭ��ΪCourier, 10��
    virtual void SetNumberFont(const std::string& family, int pointSize, int weight=VBF::Normal, bool bItalic=false)=0;
	virtual void GetNumberFont(std::string& family, int& pointSize, int& weight, bool& bItalic)=0;

    // ����/��ȡ����������̶�ֵ����ɫ��Ĭ��Ϊ��ɫ��
    virtual void	   SetNumberColor(const osg::Vec4f& val)=0;
	virtual osg::Vec4f GetNumberColor()=0;

    // �������������ᶼʹ�����Կ̶ȷ�
    virtual void SetStandardScale()=0;

    // ����/��ȡ��������̶�ֵ֮��ļ������λ�����أ�Ĭ��Ϊ0��
    virtual void SetNumberGap(int val)=0;
	virtual int  GetNumberGap()=0;

    // ����/��ȡ���������ǩ֮��ļ������λ�����أ�Ĭ��Ϊ0��
    virtual void SetLabelGap(int val)=0;
	virtual int  GetLabelGap()=0;

    // ����/��ȡ�����������ǩ�����壨Ĭ��ΪCourier, 12��
    virtual void SetLabelFont(const std::string& family, int pointSize, int weight=VBF::Normal, bool bItalic=false)=0;
	virtual void GetLabelFont(std::string& family, int& pointSize, int& weight, bool& bItalic)=0;

    // ����/��ȡ�����������ǩ����ɫ��Ĭ��Ϊ��ɫ��
    virtual void		SetLabelColor(const osg::Vec4f& val)=0;
	virtual  osg::Vec4f GetLabelColor()=0;

    // ����/��ȡ���������ἰ��̶ȵ��߿���Ĭ��Ϊ1.0��
    virtual void   SetLineWidth(double val, double majfac=0.9, double minfac=0.5)=0;
	virtual double GetLineWidth()=0;

    // ����/��ȡ�����������Ƿ����Զ���ע�̶ȣ�Ĭ��Ϊtrue��
    virtual void SetAutoScale(bool val=true)=0;
	virtual bool IsAutoScale()=0;

    // ����/��ȡ�������Ƿ��Զ�װ�Σ�Ĭ��Ϊtrue��
    virtual void SetAutoDecoration(bool val=true)=0;
    virtual bool IsAutoDecoration() const=0;

    // ����/��ȡ�������Ƿ������߹⻬��Ĭ��Ϊtrue��
    virtual void SetLineSmooth(bool val=true)=0;
    virtual bool IsLineSmooth() const=0;

    // ����/��ȡ��Ҫ�������������ߵ��棬�����Ƕ�������ϣ�Ĭ��Ϊ�����ƣ�
    virtual void SetGridSides(bool majors, bool minors, int sides=VBF::NOSIDEGRID)=0;
    virtual int  GetGridSides() const=0;

    // ����/��ȡ���������ߵ���ɫ��Ĭ��Ϊ��ɫ��
    virtual void       SetGridLinesColor(const osg::Vec4f& val)=0;
    virtual osg::Vec4f GetGridLinesColor()=0;


    //========================= ���º����������õ���������Ĳ��� ================================

    // ����/��ȡĳ��������Ŀ̶��Ƿ�Գƣ�Ĭ��Ϊfalse��
    virtual void SetSymmetricTics(VBF::AXIS nAxis, bool val)=0;
    virtual bool IsSymmetricTics(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ���������ǩ������
    virtual void SetLabelFont(VBF::AXIS nAxis, const std::string& family, int pointSize, int weight=VBF::Normal, bool bItalic=false)=0;
    virtual void GetLabelFont(VBF::AXIS nAxis, std::string& family, int& pointSize, int& weight, bool& bItalic)=0;

    // ����/��ȡĳ���������ǩ���ַ���
    virtual void        SetLabelString(VBF::AXIS nAxis, const std::string& name)=0;
    virtual std::string GetLabelString(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ���������ǩ����ɫ
    virtual void       SetLabelColor(VBF::AXIS nAxis, const osg::Vec4f& val)=0;
    virtual osg::Vec4f GetLabelColor(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ��������ı�ǩ�Ƿ�ɼ���Ĭ��Ϊfalse����������Զ�װ�Σ������Ϊtrue��
    virtual void SetLabelVisible(VBF::AXIS nAxis, bool val)=0;
    virtual bool IsLabelVisible(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ�������������ǩ֮��ļ������λ�����أ�Ĭ��Ϊ0��
    virtual void SetLabelGap(VBF::AXIS nAxis, int val)=0;
    virtual int  GetLabelGap(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ��������Ŀ̶��Ƿ�ɼ���Ĭ��Ϊfalse����������Զ�װ�Σ������Ϊtrue��
    virtual void SetScaleVisible(VBF::AXIS nAxis, bool val)=0;
    virtual bool IsScaleVisible(VBF::AXIS nAxis) const=0;

    // ����/��ȡĳ��������Ŀ̶�ֵ�Ƿ�ɼ���Ĭ��Ϊfalse����������Զ�װ�Σ������Ϊtrue��
    virtual void SetNumberVisible(VBF::AXIS nAxis, bool val)=0;
    virtual bool IsNumberVisible(VBF::AXIS nAxis) const=0;

    // ����/��ȡĳ��������̶�ֵ����ɫ
    virtual void       SetNumberColor(VBF::AXIS nAxis, const osg::Vec4f& val)=0;
    virtual osg::Vec4f GetNumberColor(VBF::AXIS nAxis) const=0;

    // ����/��ȡĳ��������̶�ֵ������
    virtual void SetNumberFont(VBF::AXIS nAxis, const std::string& family, int pointSize, int weight=VBF::Normal, bool bItalic=false)=0;
    virtual void GetNumberFont(VBF::AXIS nAxis, std::string& family, int& pointSize, int& weight, bool& bItalic)=0;

    // ����/��ȡĳ��������̶�ֵ�Ķ�λ��ʽ��Ĭ��ΪCenter��
    virtual void SetNumberAnchor(VBF::AXIS nAxis, VBF::ANCHOR val)=0;
    virtual VBF::ANCHOR GetNumberAnchor(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ������������̶�ֵ֮��ļ������λ�����أ�Ĭ��Ϊ0��
    virtual void SetNumberGap(VBF::AXIS nAxis, int val)=0;
    virtual int  GetNumberGap(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ���������Ƿ��Զ���ע�̶ȣ���λ�����أ�Ĭ��Ϊtrue��
    virtual void SetAutoScale(VBF::AXIS nAxis, bool val=true)=0;
    virtual bool IsAutoScale(VBF::AXIS nAxis) const=0;

    // ����/��ȡĳ���������ϵ����̶ȸ�������������Զ���ע����ֵ���ܻᱻ�޸ģ�
    virtual void SetMajorCount(VBF::AXIS nAxis, int val)=0;
    virtual int  GetMajorCount(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ���������������������̶�֮��Ĵο̶ȸ���
    virtual void SetMinorCount(VBF::AXIS nAxis, int val)=0;
    virtual int  GetMinorCount(VBF::AXIS nAxis)=0;

    // ����/��ȡĳ�������ἰ���ο̶ȵ��߿�
    virtual void   SetLineWidth(VBF::AXIS nAxis, double val, double majfac=0.9, double minfac=0.5)=0;
    virtual double GetLineWidth(VBF::AXIS nAxis) const=0;
    virtual double GetMajorLineWidth(VBF::AXIS nAxis) const=0;
    virtual double GetMinorLineWidth(VBF::AXIS nAxis) const=0;
};

#endif 