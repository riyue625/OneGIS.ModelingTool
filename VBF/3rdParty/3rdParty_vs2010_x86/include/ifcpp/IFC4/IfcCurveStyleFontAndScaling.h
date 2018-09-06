/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "model/shared_ptr.h"
#include "model/IfcPPObject.h"
#include "model/IfcPPGlobal.h"
#include "IfcCurveFontOrScaledCurveFontSelect.h"
#include "IfcPresentationItem.h"
class IFCPP_EXPORT IfcLabel;
class IFCPP_EXPORT IfcCurveStyleFontSelect;
class IFCPP_EXPORT IfcPositiveRatioMeasure;
//ENTITY
class IFCPP_EXPORT IfcCurveStyleFontAndScaling : virtual public IfcCurveFontOrScaledCurveFontSelect, public IfcPresentationItem
{ 
public:
	IfcCurveStyleFontAndScaling();
	IfcCurveStyleFontAndScaling( int id );
	~IfcCurveStyleFontAndScaling();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcCurveStyleFontAndScaling"; }


	// IfcPresentationItem -----------------------------------------------------------

	// IfcCurveStyleFontAndScaling -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcLabel>				m_Name;						//optional
	shared_ptr<IfcCurveStyleFontSelect>	m_CurveFont;
	shared_ptr<IfcPositiveRatioMeasure>	m_CurveFontScaling;
};
