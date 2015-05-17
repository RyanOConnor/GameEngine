#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class ContentManager
{
public:
	template<typename T> 
	void Load( const std::string & resourceName, const std::string & fileName );

	template<typename T> 
	T * Find( const std::string & resourceName );

	static ContentManager * GetInstance();

private:
	ContentManager();

	std::map<std::string, sf::Texture *> textureMap;

	static ContentManager * instance;
};

#endif