#ifndef SFMLKEYBOARD_H
#define SFMLKEYBOARD_H

#include <SFML/Graphics.hpp>

class sfmlKeyboard
{
public:
	sfmlKeyboard();
	virtual ~sfmlKeyboard();
	static bool isKeyPressed( sf::Keyboard::Key key);
	static bool isKeyDown(sf::Keyboard::Key key);
	static bool isKeyReleased(sf::Keyboard::Key key);
	static bool isKeyUp(sf::Keyboard::Key key);
		
	static void Update();
	static void HandleEvents( sf::Keyboard::Key key, bool keyB );

private:
	static bool current[101];
	static bool previous[101];
};

#endif