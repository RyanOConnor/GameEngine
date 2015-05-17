#ifndef TREASURE_H
#define TREASURE_H

#include "Object.h"

enum TreasureType
{
	Water,
	Fire,
	Mallet,
	Rifle,
	Stake
};

class Treasure : public Object
{
public:
	Treasure( const sf::Vector2f & startingPosition, TreasureType t );

	virtual void Update();
	virtual void Draw();

private:
	TreasureType treasureType;
	sf::Text type;
	sf::Text points;
	sf::Font font;
	bool retrieved;
	bool viewing;

};

#endif