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
#include "IfcBoundedSurface.h"
class IFCPP_EXPORT IfcInteger;
class IFCPP_EXPORT IfcCartesianPoint;
class IFCPP_EXPORT IfcBSplineSurfaceForm;
class IFCPP_EXPORT IfcLogical;
//ENTITY
class IFCPP_EXPORT IfcBSplineSurface : public IfcBoundedSurface
{ 
public:
	IfcBSplineSurface();
	IfcBSplineSurface( int id );
	~IfcBSplineSurface();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcBSplineSurface"; }


	// IfcRepresentationItem -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
	//  std::vector<weak_ptr<IfcStyledItem> >					m_StyledByItem_inverse;

	// IfcGeometricRepresentationItem -----------------------------------------------------------

	// IfcSurface -----------------------------------------------------------

	// IfcBoundedSurface -----------------------------------------------------------

	// IfcBSplineSurface -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcInteger>									m_UDegree;
	shared_ptr<IfcInteger>									m_VDegree;
	std::vector<std::vector<shared_ptr<IfcCartesianPoint> > >	m_ControlPointsList;
	shared_ptr<IfcBSplineSurfaceForm>						m_SurfaceForm;
	shared_ptr<IfcLogical>									m_UClosed;
	shared_ptr<IfcLogical>									m_VClosed;
	shared_ptr<IfcLogical>									m_SelfIntersect;
};
