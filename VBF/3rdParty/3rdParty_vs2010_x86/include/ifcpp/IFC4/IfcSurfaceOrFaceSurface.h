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
#include <iostream>
#include <sstream>
#include <map>
#include "model/shared_ptr.h"
#include "model/IfcPPObject.h"

// TYPE IfcSurfaceOrFaceSurface = SELECT	(IfcFaceBasedSurfaceModel	,IfcFaceSurface	,IfcSurface);
class IFCPP_EXPORT IfcSurfaceOrFaceSurface : virtual public IfcPPObject
{
public:
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options ) = 0;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0;
	static shared_ptr<IfcSurfaceOrFaceSurface> createObjectFromSTEP( const std::wstring& arg, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map );
};
