//***************************************************************************************
// FileName��VBF_TileSourceOptions.h
// Function���ؿ�����Դѡ��
// Author:
// Date:
//***************************************************************************************

#ifndef __VECTOR_TILE_SOURCE_OPTIONS_H__
#define __VECTOR_TILE_SOURCE_OPTIONS_H__

#include <VBF_Common/VBF_Utils/VBF_Config.h>
#include <VBF_3DMap/VBF_Terrain/VBF_SourceTile.h>
#include <VBF_3DMap/VBF_Terrain/HeightFieldUtils.h>
#include <VBF_3DMap/VBF_Terrain/URI.h>
using namespace osgEarth;

class CVBF_TileSourceVectorOptions : public CVBF_OptionsDriverSourceTile // NO EXPORT; header only
{
public: // properties
	CVBF_Optional<URI>&		 GetURL()		{ return m_url; }
	const CVBF_Optional<URI>& GetURL() const	{ return m_url; }
	
public: // ctors
    CVBF_TileSourceVectorOptions(const CVBF_OptionsDriverSourceTile& options =CVBF_OptionsDriverSourceTile() ) :
		CVBF_OptionsDriverSourceTile( options )
		{
            setDriver( "vector" );
			fromConfig(m_conf);
		}

virtual ~CVBF_TileSourceVectorOptions() {}

public:

	CVBF_Config getConfig() const
	{
		CVBF_Config conf = CVBF_OptionsDriverSourceTile::getConfig();
		conf.updateIfSet( "url", m_url );

		return conf;
	}

	void mergeConfig( const CVBF_Config& conf ) 
	{
		CVBF_OptionsDriverSourceTile::mergeConfig( conf );
		fromConfig( conf );
	}

	void fromConfig( const CVBF_Config& conf ) 
	{
		conf.getIfSet( "url", m_url );
	}

protected:
	CVBF_Optional<URI>		m_url;  // ����·��
};


#endif