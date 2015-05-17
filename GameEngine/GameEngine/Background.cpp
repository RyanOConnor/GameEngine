#include "Background.h"
#include "SFMLGame.h"

Background::Background( const sf::Vector2f & startingPosition,
					   const sf::String & labelName,
					   const sf::String & resourceName,
					   const sf::String & resourceFile )
		: Object( resourceName, resourceFile, startingPosition, 1, 1)
{
	// nothing
}