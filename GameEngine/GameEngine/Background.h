#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Object.h"

class Background : public Object
{
public:
	Background( const sf::Vector2f & startingPosition,
				const sf::String & name = "Background",
				const sf::String & resourceName = "background",
				const sf::String & resourceFile = "background.png" );

private:

};

#endif