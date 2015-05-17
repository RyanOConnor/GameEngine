#include "Button.h"
#include "SFMLGame.h"

Button::Button( const sf::Vector2f & startingPosition,
				CallBackType callBack,
				const sf::String & buttonText,
				const sf::String & resourceName,
				const sf::String & resourceFile )
	: Object( resourceName, resourceFile, startingPosition, 3, 1 ),
	  CallBackFunction( callBack )
{
	font.loadFromFile("forced square.ttf");
	text.setFont( font );
	text.setString( buttonText );
	text.setCharacterSize( 48 );
	text.setColor( sf::Color(255, 51, 0) );

	text.setPosition( X(), Y() );
	sf::Vector2f g = text.findCharacterPos(9);
	text.setPosition( X() + ( 155 - ( ( g.x - X() ) / 2 ) ), Y() + 40 );
}

void Button::Update()
{
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
		CallBackFunction();
	}

	Object::Update();
}

void Button::Draw()
{
	if( visible == true )
	{
		Object::Draw();
		SFMLGame::GetInstance()->GetWindow()->draw( text );
	}
}