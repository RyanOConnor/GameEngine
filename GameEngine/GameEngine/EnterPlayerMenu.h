#ifndef ENTERPLAYERMENU_H
#define ENTERPLAYERMENU_H

#include "Object.h"
#include "PlayerList.h"
#include "EnterPlayerScene.h"

class EnterPlayerMenu : public Object
{
public:
	typedef void (EnterPlayerScene::*CallBackType)( sf::String, int );

	EnterPlayerMenu( const sf::Vector2f & startPosition,
					 int curPlayer,
					 CallBackType cBack,
					 const sf::String & fieldText,
					 int key = 0,
					 const sf::String & rName = "nameField",
					 const sf::String & rFile = "typeField.png" );

	virtual void Update();
	virtual void Draw();

	PlayerList * list;

private:
	CallBackType EnterKeyPressed;

	sf::Font font;
	sf::Text labelText;
	sf::Text fieldText;
	sf::String fieldString;
	bool previousFrame;
	int key;
	const char * keyValues;

	std::vector<sf::String> names;
};

#endif