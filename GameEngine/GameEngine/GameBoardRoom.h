#ifndef GAMEBOARDROOM_H
#define GAMEBOARDROOM_H

#include "Object.h"

class Creature;
class Treasure;

class GameBoardRoom : public Object
{
public:
	typedef void (*CallBackType)( Treasure *, bool );

	GameBoardRoom( const sf::Vector2f & position, int rng, CallBackType tBack );

	virtual void Update();
	virtual void Draw();
	void Goodbye();

private:
	CallBackType PassTreasure;

	Creature * creature;
	Treasure * treasure;
	bool turnUsed;
	int speed;
	int rotate;
};

#endif