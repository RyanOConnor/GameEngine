#include "GameBoardRoom.h"
#include "GameBoard.h"
#include "SFMLGame.h"
#include "Creature.h"
#include "Treasure.h"

GameBoardRoom::GameBoardRoom( const sf::Vector2f & position,
							 int rng,
							 CallBackType tBack )
	: Object( "space", "button.png", position, 3, 1 ),
	  PassTreasure( tBack )
{
	creature = new Creature( sf::Vector2f( position.x, position.y ), 
		static_cast<CreatureType>(rng) );

	treasure = new Treasure( sf::Vector2f( position.x, position.y ), 
		static_cast<TreasureType>(rng) );

	turnUsed = false;
	speed = 0;
	rotate = 0;
}

void GameBoardRoom::Update()
{
	sf::Vector2i mousePosition = 
		sf::Mouse::getPosition( *SFMLGame::GetInstance()->GetWindow() );

	bool isInBounds =
	    ( mousePosition.x >= X() ) && 
		( mousePosition.x < ( X() + SpriteWidth() ) ) &&
		( mousePosition.y >= Y() ) &&
		( mousePosition.y < ( Y() + SpriteHeight() ) );

	SetImageIndex( ( isInBounds ) ? 2 : 1 );

	if( ( creature->GetCurrentStrength() <= 0 ) && ( visible == true ) )
	{
		Goodbye();
		if( ( Object::X() > 1500 ) || ( Object::X() < -400 ) || 
			( Object::Y() > 1000 ) || ( Object::Y() < -200 ) )
		{
			SetVisible(false);
			PassTreasure( treasure, false );
		}
	}

	if( ( sf::Mouse::isButtonPressed( sf::Mouse::Button::Left ) ) && 
		( isInBounds ) && ( turnUsed == false ) )
	{
		SetImageIndex( 0 );

		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		int roll = die1 + die2;

		creature->Damage( roll );

		// TODO: instead of a bool value, create frame counter with modulus
		turnUsed = true;

		// call GameScene::PassTreasure and pass in 2nd variable of bool
		PassTreasure( treasure, true );
	}

	if( ( !isInBounds ) || ( !sf::Mouse::isButtonPressed( sf::Mouse::Button::Left ) ) )
	{
		turnUsed = false;
	}

	creature->Update();
	treasure->Update();

	Object::Update();
}

void GameBoardRoom::Draw()
{
	Object::Draw();
	if( visible == true )
	{
		Object::Draw();
		creature->Draw();
		treasure->Draw();
	}
}

void GameBoardRoom::Goodbye()
{
	speed = rand() % 360;
	if( speed % 15 == 0 )
	{
		Object::SetVAcceleration( 0.1 );
		Object::SetHAcceleration( 0.1 );
	}
	else if ( speed % 14 == 0 )
	{
		Object::SetVAcceleration( -0.1 );
		Object::SetHAcceleration( 0.1 );
	}
	else if ( speed % 13 == 0 )
	{
		Object::SetVAcceleration( -0.1 );
		Object::SetHAcceleration( -0.1 );
	}
	else if ( speed % 11 == 0 )
	{
		Object::SetVAcceleration( 0.1 );
		Object::SetHAcceleration( -0.1 );
	}
	//++rotate;
	Object::GetSprite()->setRotation(speed);
}