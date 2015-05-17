#include "PlayerList.h"
#include "PlayerLabel.h"
#include "SFMLGame.h"
#include "GameScene.h"

PlayerList::PlayerList( std::vector<sf::String> names, int numPlayers )
	: Object( "label", "button.png", sf::Vector2f( 0, 0 ), 3, 1 )
{
	int i = 0;
	while( ( names.size() > 0 ) && ( i < names.size() ) && ( i < numPlayers ) )
	{
		float x = ( 1560 / numPlayers ) * ( i % numPlayers );
		labels.push_back( new PlayerLabel( sf::Vector2f( x + ( 500 / numPlayers ) - ( numPlayers * 15 ), 
			725 ), names[i] ) );
		++i;
	}
}

void PlayerList::Update()
{
	std::vector<PlayerLabel *>::iterator iter;
	for( iter = labels.begin(); iter != labels.end(); ++iter )
	{
		(*iter)->Update();
	}
}

void PlayerList::Draw()
{
	if( visible == true )
	{
		std::vector<PlayerLabel *>::iterator iter;
		for( iter = labels.begin(); iter != labels.end(); ++iter )
		{
			(*iter)->Draw();
		}
	}
}