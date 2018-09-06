#pragma once
#include "AC_ItemGraphic.h"
class C_ItemGeometry : public AC_ItemGraphic
{
public:
	C_ItemGeometry(QString sName);
	~C_ItemGeometry(void);

	virtual void setItemType(const E_ItemType& eType){setData(0,E_ItemType::Geometry);};
	virtual QRectF boundingRect() const;

	double getDiameter() const{return m_dDiameter;};

	void setDiameter(const double& dDiameter){m_dDiameter = dDiameter;};

	bool getFoldState(){return m_bFolded;};

	void changeFoldState();

protected:
	void paint(QPainter* pPainter, const QStyleOptionGraphicsItem* pOption, QWidget* pWidget);

private:
	// ��ȡ������ռ�ľ��δ�С
	virtual QRectF outlineRect() const;

private:
	double m_dDiameter;
	bool m_bFolded;
	QPolygonF m_triangle;
};
