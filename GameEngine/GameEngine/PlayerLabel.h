#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H

#include "Object.h"

class Treasure;

class PlayerLabel : public Object
{
public:
	PlayerLabel( const sf::Vector2f & startingPosition, 
			const sf::String & labelName = "Enter Player",
			const sf::String & resourceName = "label",
			const sf::String & resourceFile = "button.png" );
	
	virtual void Update();
	virtual void Draw();

	void AddTreasure( Treasure * t );
	void SetCurrentlyPlaying( bool turnStatus );

private:
	sf::Font font;
	sf::Text name;
	sf::Text treasure;
	sf::Text playerTurn;

	std::vector<Treasure *> heldTreasure;
	sf::String treasureString;
	sf::String player;
	const char * treasureValues;
	bool currentlyPlaying;
};

#endif