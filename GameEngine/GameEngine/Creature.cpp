#include "Creature.h"
#include "SFMLGame.h"

Creature::Creature( const sf::Vector2f & position, CreatureType c )
	: Object( "Creature", "button.png", position, 3, 1 )
{
	creatureType = c;
	dead = false;

	strengthValues = "0123456789";

	if( creatureType == CreatureType::Dragon )
	{
		type.setString( "Dragon" );
		inStrength = rand() % 14 + 7;
		curStrength = inStrength;
		SetHealth(curStrength, inStrength);
	}
	else if( creatureType == CreatureType::Troll )
	{
		type.setString( "Troll" );
		inStrength = rand() % 14 + 7;
		curStrength = inStrength;
		SetHealth(curStrength, inStrength);
	}
	else if( creatureType == CreatureType::Skeleton )
	{
		type.setString( "Skeleton" );
		inStrength = rand() % 14 + 7;
		curStrength = inStrength;
		SetHealth(curStrength, inStrength);
	}
	else if( creatureType == CreatureType::Orc )
	{
		type.setString( "Orc" );
		inStrength = rand() % 14 + 7;
		curStrength = inStrength;
		SetHealth(curStrength, inStrength);
	}
	else if( creatureType == CreatureType::Vampire )
	{
		type.setString( "Vampire" );
		inStrength = rand() % 14 + 7;
		curStrength = inStrength;
		SetHealth(curStrength, inStrength);
	}

	font.loadFromFile("forced square.ttf");
	type.setFont( font );
	type.setCharacterSize( 52 );
	type.setColor( sf::Color(255, 51, 0) );
	type.setPosition( X(), Y() );
	sf::Vector2f t = type.findCharacterPos(8);
	type.setPosition( X() + ( 155 - ( ( t.x - X() ) / 2 ) ), Y() );

	health.setFont( font );
	health.setCharacterSize( 44 );
	health.setColor( sf::Color(80, 80, 80) );
	health.setPosition( X(), Y() );
	sf::Vector2f h = health.findCharacterPos(7);
	health.setPosition( X() + ( 155 - ( ( t.x - X() ) / 2 ) ), Y() + 92 );
}

void Creature::Update()
{
	sf::Vector2i mousePosition = 
		sf::Mouse::getPosition( *SFMLGame::GetInstance()->GetWindow() );

	bool isInBounds =
	    ( mousePosition.x >= X() ) && 
		( mousePosition.x < ( X() + SpriteWidth() ) ) &&
		( mousePosition.y >= Y() ) &&
		( mousePosition.y < ( Y() + SpriteHeight() ) );

	if (isInBounds && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		view = true;
	}

	if (curStrength <= 0)
	{
		dead = true;
	}

	SetHealth(curStrength, inStrength);

	Object::Update();
}

void Creature::Draw()
{
	if( ( visible == true ) && ( view == true ) && ( dead == false ) )
	{
		SFMLGame::GetInstance()->GetWindow()->draw( type );
		SFMLGame::GetInstance()->GetWindow()->draw( health );
	}
}

void Creature::Damage( int d )
{
	curStrength -= d;
}

void Creature::SetHealth( int curStrength, int inStrength )
{
	if( curStrength < 10)
	{
		str1 = strengthValues[curStrength];
	}
	else if( curStrength >= 10)
	{
		str1 = strengthValues[1];
		str1 += strengthValues[curStrength % 10];
	}

	if( inStrength < 10)
	{
		str2 = strengthValues[inStrength];
	}
	else if( inStrength >= 10)
	{
		str2 = strengthValues[1];
		str2 += strengthValues[inStrength % 10];
	}

	health.setString( str1 + " / " + str2 );
}

int Creature::GetCurrentStrength()
{
	return curStrength;
}