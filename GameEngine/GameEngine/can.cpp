#include "can.h"

Can::Can( const sf::String & resourceName,
		 const sf::String & resourceFile )
		 : Object( resourceName, resourceFile, sf::Vector2f() )
{
	// nothing here....
}

void Can::Update()
{
	GetSprite()->move( 3, 0 );
}