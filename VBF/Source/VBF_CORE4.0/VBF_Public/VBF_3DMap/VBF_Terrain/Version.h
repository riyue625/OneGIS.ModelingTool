/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
* Copyright 2008-2013 Pelican Mapping
* http://osgearth.org
*
* osgEarth is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#ifndef OSGEARTH_VERSION
#define OSGEARTH_VERSION 1

#include <VBF_3DMap/VBF_Terrain/Export>

extern "C" {

#define OSGEARTH_MAJOR_VERSION    2
#define OSGEARTH_MINOR_VERSION    4
#define OSGEARTH_PATCH_VERSION    0
#define OSGEARTH_SOVERSION        0
#define OSGEARTH_RC_VERSION       0

/* Convenience macro that can be used to decide whether a feature is present or not i.e.
 * #if OSGEARTH_MIN_VERSION_REQUIRED(1,4,0)
 *    your code here
 * #endif
 */
#define OSGEARTH_MIN_VERSION_REQUIRED(MAJOR, MINOR, PATCH) ((OSGEARTH_MAJOR_VERSION>MAJOR) || (OSGEARTH_MAJOR_VERSION==MAJOR && (OSGEARTH_MINOR_VERSION>MINOR || (OSGEARTH_MINOR_VERSION==MINOR && OSGEARTH_PATCH_VERSION>=PATCH))))
#define OSGEARTH_VERSION_LESS_THAN(MAJOR, MINOR, PATCH) ((OSGEARTH_MAJOR_VERSION<MAJOR) || (OSGEARTH_MAJOR_VERSION==MAJOR && (OSGEARTH_MINOR_VERSION<MINOR || (OSGEARTH_MINOR_VERSION==MINOR && OSGEARTH_PATCH_VERSION<PATCH))))
#define OSGEARTH_VERSION_LESS_OR_EQUAL(MAJOR, MINOR, PATCH) ((OSGEARTH_MAJOR_VERSION<MAJOR) || (OSGEARTH_MAJOR_VERSION==MAJOR && (OSGEARTH_MINOR_VERSION<MINOR || (OSGEARTH_MINOR_VERSION==MINOR && OSGEARTH_PATCH_VERSION<=PATCH))))
#define OSGEARTH_VERSION_GREATER_THAN(MAJOR, MINOR, PATCH) ((OSGEARTH_MAJOR_VERSION>MAJOR) || (OSGEARTH_MAJOR_VERSION==MAJOR && (OSGEARTH_MINOR_VERSION>MINOR || (OSGEARTH_MINOR_VERSION==MINOR && OSGEARTH_PATCH_VERSION>PATCH))))
#define OSGEARTH_VERSION_GREATER_OR_EQUAL(MAJOR, MINOR, PATCH) ((OSGEARTH_MAJOR_VERSION>MAJOR) || (OSGEARTH_MAJOR_VERSION==MAJOR && (OSGEARTH_MINOR_VERSION>MINOR || (OSGEARTH_MINOR_VERSION==MINOR && OSGEARTH_PATCH_VERSION>=PATCH))))


/**
  * osgEarthGetVersion() returns the library version number.
  * Numbering convention : OSGEARTH-1.0 will return 1.0 from osgEarthGetVersion.
  *
  * This C function can be also used to check for the existence of the OSGEARTH
  * library using autoconf and its m4 macro AC_CHECK_LIB.
  *
  * Here is the code to add to your configure.in:
 \verbatim
 #
 # Check for the OSGEARTH (OSG) library
 #
 AC_CHECK_LIB(osg, osgEarthGetVersion, ,
    [AC_MSG_ERROR(OSGEARTH library not found. See http://www.osgearth.org)],)
 \endverbatim
*/
extern OSGEARTH_EXPORT const char* osgEarthGetVersion();

/** The osgGetSOVersion() method returns the OSGEARTH shared object version number. */
extern OSGEARTH_EXPORT const char* osgEarthGetSOVersion();

/** The osgGetLibraryName() method returns the library name in human-friendly form. */
extern OSGEARTH_EXPORT const char* osgEarthGetLibraryName();

#define OSGEARTH_VERSION_RELEASE OSGEARTH_VERSION_PATCH
#define OSGEARTH_VERSION_REVISION 0
}

#endif