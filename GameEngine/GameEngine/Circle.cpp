#include "Circle.h"
#include "ContentManager.h"
#include "SFMLGame.h"
#include "sfmlKeyboard.h"
#include "SecondScene.h"

Circle::Circle( const sf::Vector2f & startingPosition )
	: Object( "smiley", "anim.png", startingPosition, 12, 8 )
{
	sprite->setPosition( startingPosition );
	//SFMLGame::GetInstance()->SetFixedTimeSteps( false );
}

void Circle::Update()
{
	if (sfmlKeyboard::isKeyDown(sf::Keyboard::Key::Down))
	{
			sprite->move(0,3);
	}
	if (sfmlKeyboard::isKeyDown(sf::Keyboard::Key::Up))
	{
			sprite->move(0,-3);
	}
	if (sfmlKeyboard::isKeyDown(sf::Keyboard::Key::Left))
	{
			sprite->move(-3,0);
	}
	if (sfmlKeyboard::isKeyDown(sf::Keyboard::Key::Right))
	{
			sprite->move(3,0);
	}

	if(sfmlKeyboard::isKeyDown(sf::Keyboard::Key::Space))
	{
		SFMLGame::GetInstance()->ChangeCurrentScene( new SecondScene() );
	}

	Object::Update();
}