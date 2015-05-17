#include "Treasure.h"
#include "sfmlKeyboard.h"
#include "SFMLGame.h"

Treasure::Treasure( const sf::Vector2f & position, TreasureType t )
	: Object( "Treasure", "button.png", position, 3, 1 )
{
	treasureType = t;
	viewing = false;
	retrieved = false;

	if( treasureType == TreasureType::Water )
	{
		type.setString( "Water" );
	}
	else if( treasureType == TreasureType::Fire )
	{
		type.setString( "Fire" );
	}
	else if( treasureType == TreasureType::Mallet )
	{
		type.setString( "Mallet" );
	}
	else if( treasureType == TreasureType::Rifle )
	{
		type.setString( "Rifle" );
	}
	else if( treasureType == TreasureType::Stake )
	{
		type.setString( "Stake" );
	}


	font.loadFromFile( "forced square.ttf" );
	type.setFont( font );
	type.setCharacterSize( 48 );
	type.setColor( sf::Color(80,80,80) );
	type.setPosition( X(), Y() );
	sf::Vector2f tr = type.findCharacterPos(8);
	type.setPosition( X() + ( 155 - ( ( tr.x - X() ) / 2 ) ), Y() + 50 );
}

void Treasure::Update()
{
	sf::Vector2i mousePosition = 
		sf::Mouse::getPosition( *SFMLGame::GetInstance()->GetWindow() );

	bool isInBounds =
	    ( mousePosition.x >= X() ) && 
		( mousePosition.x < ( X() + SpriteWidth() ) ) &&
		( mousePosition.y >= Y() ) &&
		( mousePosition.y < ( Y() + SpriteHeight() ) );

	if( ( viewing == true ) && ( sfmlKeyboard::isKeyPressed( sf::Keyboard::Key::Return ) ) )
	{
		retrieved = true;
	}

	if( isInBounds && sf::Mouse::isButtonPressed( sf::Mouse::Button::Left) )
	{
		viewing = true;
	}


	Object::Update();
}

void Treasure::Draw()
{
	if( ( visible == true ) && ( viewing == true ) && ( retrieved == false ) )
	{
		SFMLGame::GetInstance()->GetWindow()->draw( type );
	}
}