#include "PlayerLabel.h"
#include "SFMLGame.h"
#include "Treasure.h"

PlayerLabel::PlayerLabel( const sf::Vector2f & startingPosition,
				const sf::String & labelName,
				const sf::String & resourceName,
				const sf::String & resourceFile )
	: Object( resourceName, resourceFile, startingPosition, 3, 1 )
{
	treasureString = "Treasure: 0";
	treasureValues = "0123456789";
	player += labelName + "'s Turn";
	currentlyPlaying = false;

	font.loadFromFile("forced square.ttf");
	
	name.setFont( font );
	name.setString( labelName );
	name.setCharacterSize( 58 );
	name.setColor( sf::Color(255, 51, 0) );
	name.setPosition( X(), Y() );
	sf::Vector2f n = name.findCharacterPos(9);
	name.setPosition( X() + ( 155 - ( ( n.x - X() ) / 2 ) ), Y() + 15 );

	treasure.setFont( font );
	treasure.setString( treasureString );
	treasure.setCharacterSize( 52 );
	treasure.setColor( sf::Color::White );
	treasure.setPosition( X(), Y() );
	sf::Vector2f p = treasure.findCharacterPos(12);
	treasure.setPosition( X() + ( 155 - ( ( p.x - X() ) / 2 ) ), Y() + 75 );

	playerTurn.setFont( font );
	playerTurn.setString( treasureString );
	playerTurn.setCharacterSize( 42 );
	playerTurn.setColor( sf::Color::White);
	playerTurn.setPosition( X(), Y() );
	playerTurn.setPosition( 660, 655 );
}

void PlayerLabel::Update()
{
	treasure.setString( treasureString );
	playerTurn.setString( player );

	sf::Vector2i mousePosition = 
		sf::Mouse::getPosition( *SFMLGame::GetInstance()->GetWindow() );

	bool isInBounds =
	    ( mousePosition.x >= X() ) && 
		( mousePosition.x < ( X() + SpriteWidth() ) ) &&
		( mousePosition.y >= Y() ) &&
		( mousePosition.y < ( Y() + SpriteHeight() ) );

	SetImageIndex( ( isInBounds ) ? 1 : 0 );

	if( isInBounds && sf::Mouse::isButtonPressed( sf::Mouse::Button::Left ) )
	{
		SetImageIndex( 2 );
	}


	Object::Update();
}

void PlayerLabel::Draw()
{
	if( visible == true )
	{
		Object::Draw();
		SFMLGame::GetInstance()->GetWindow()->draw( name );
		SFMLGame::GetInstance()->GetWindow()->draw( treasure );
	}

	if( currentlyPlaying == true )
	{	
		SFMLGame::GetInstance()->GetWindow()->draw( playerTurn );
	}
}

void PlayerLabel::AddTreasure( Treasure * t )
{
	heldTreasure.push_back( t );

	int vectorSize = heldTreasure.size();

	if( vectorSize < 10 )
	{
		treasureString = "Treasure: ";
		treasureString += treasureValues[vectorSize];
	}
	else if ( heldTreasure.size() >= 10 )
	{
		treasureString = "Treasure: ";
		treasureString += treasureValues[1];
		treasureString += treasureValues[vectorSize % 10];
	}
}

void PlayerLabel::SetCurrentlyPlaying( bool turnStatus )
{
	currentlyPlaying = turnStatus;
}