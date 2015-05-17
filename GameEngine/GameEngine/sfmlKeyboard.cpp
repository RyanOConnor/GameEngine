#include "sfmlKeyboard.h"


bool sfmlKeyboard::current[101] = {false};
bool sfmlKeyboard::previous[101] = {false};

sfmlKeyboard::sfmlKeyboard()
{
	// nothing
}

sfmlKeyboard::~sfmlKeyboard()
{
	// nothing
}

bool sfmlKeyboard::isKeyPressed(sf::Keyboard::Key key)
{
	if( ( current[key] == true ) && ( previous[101] == false ) )
		return true;
	else
		return false;
}

bool sfmlKeyboard::isKeyDown(sf::Keyboard::Key key)
{
	return current[key];
}

bool sfmlKeyboard::isKeyReleased(sf::Keyboard::Key key)
{
	if((current[key] == false) && (previous[101] == true))
		return true;
	else
		return false;
}

bool sfmlKeyboard::isKeyUp(sf::Keyboard::Key key)
{
	if(current[key] == false)
		return true;
	else
		return false;
}

void sfmlKeyboard::Update()
{
	for( unsigned int i = 0; i < 101; ++i)
	{
		previous[i] = current[i];
	}
}

void sfmlKeyboard::HandleEvents(sf::Keyboard::Key key, bool keyB)
{
	current[key] = keyB;
}