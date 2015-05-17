#include "EnterPlayerMenu.h"
#include "SFMLGame.h"
#include "sfmlKeyboard.h"
#include <sstream>


EnterPlayerMenu::EnterPlayerMenu( const sf::Vector2f & startPosition,
				 int curPlayer,
				 CallBackType cBack,
				 const sf::String & fieldLabel,
				 int passedKey,
				 const sf::String & rName,
				 const sf::String & rFile )
		: Object( rName, rFile, startPosition, 1, 1 ),
		  EnterKeyPressed( cBack )
{
	font.loadFromFile("forced square.ttf");
	labelText.setFont( font );

	std::stringstream ss;
	ss << curPlayer;
	sf::String label = fieldLabel + ss.str().c_str();

	labelText.setString( label );
	labelText.setCharacterSize( 56 );
	labelText.setColor( sf::Color(255, 51, 0) );
	labelText.setPosition( X() + 300, Y() - 80 );

	fieldText.setFont( font );
	fieldText.setCharacterSize( 56 );
	fieldText.setColor( sf::Color(255, 51, 0 ) );
	fieldText.setPosition( X() + 15, Y() + 10 );

	previousFrame = false;
	key = passedKey;
	keyValues = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" ;
}

void EnterPlayerMenu::Update()
{
	fieldText.setString( fieldString );
	sf::Vector2f g = fieldText.findCharacterPos(30);
	fieldText.setPosition( X() + ( 600 - ( ( g.x - X() ) / 2 ) ), Y() + 10 );

	if( sfmlKeyboard::isKeyUp( static_cast<sf::Keyboard::Key>(key) ) )
	{
		previousFrame = false;
		key = 0;
	}

	while( ( key < 36 ) && ( previousFrame == false ) )
	{
		if ( ( sfmlKeyboard::isKeyPressed( sf::Keyboard::Key::BackSpace ) ) &&
			  ( fieldString.getSize() > 0 ) )
		{
			previousFrame = true;
			fieldString.erase(fieldString.getSize() - 1, 1);
			key = 59;
			break;
		}
		else if( sfmlKeyboard::isKeyPressed( sf::Keyboard::Key::Space ) )
		{
			previousFrame = true;
			fieldString += " ";
			key = 57;
			break;
		}
		else if( sfmlKeyboard::isKeyPressed( sf::Keyboard::Key::Return ) )
		{
			previousFrame = true;
			Scene * scene = SFMLGame::GetInstance()->GetCurrentScene();
			EnterPlayerScene * s = dynamic_cast<EnterPlayerScene *>(scene);
			s->EnterKeyPressed( fieldString, 58 );
		}
		else if( sfmlKeyboard::isKeyPressed( static_cast<sf::Keyboard::Key>(key) ) )
		{
			previousFrame = true;
			fieldString += keyValues[key];
			break;
		}
		++key;
	}

	Object::Update();
}

void EnterPlayerMenu::Draw()
{
	if( visible ==  true )
	{
		Object::Draw();
		SFMLGame::GetInstance()->GetWindow()->draw( labelText );
		SFMLGame::GetInstance()->GetWindow()->draw( fieldText );
	}
}