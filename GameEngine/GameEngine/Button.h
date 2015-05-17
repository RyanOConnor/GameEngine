#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"
#include "PlayerList.h"

class Button : public Object
{
public:
	typedef void (*CallBackType)();

	Button( const sf::Vector2f & startingPosition, 
			CallBackType callBack,
			const sf::String & buttonText = "",
			const sf::String & resourceName = "button",
			const sf::String & resourceFile = "button.png" );
	
	virtual void Update();
	virtual void Draw();

private:
	CallBackType CallBackFunction;

	sf::Font font;
	sf::Text text;
};

#endif