#include "ContentManager.h"
#include <cassert>

ContentManager * ContentManager::instance = 0;

ContentManager::ContentManager()
	: textureMap()
{
	// Nothing here...
}

ContentManager * ContentManager::GetInstance()
{
	if( instance == 0 )
	{
		instance = new ContentManager();
	}

	return instance;
}

template<>
void ContentManager::Load<sf::Texture>( const std::string & resourceName, 
		                                const std::string & fileName )
{
	sf::Texture * texture = new sf::Texture();
	bool success = texture->loadFromFile( fileName );
	assert( success );
	textureMap.insert( std::make_pair( resourceName, texture));
}

template<>
sf::Texture * ContentManager::Find<sf::Texture>( const std::string & resourceName )
{
	std::map<std::string, sf::Texture *>::iterator iter;
	iter = textureMap.find( resourceName );

	return ( iter != textureMap.end() ) ? iter->second : 0;
}