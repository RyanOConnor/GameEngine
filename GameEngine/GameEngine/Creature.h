#ifndef CREATURE_H
#define CREATURE_H

#include "Object.h"
#include "GameBoardRoom.h"

enum CreatureType
{
	Dragon,
	Troll,
	Skeleton,
	Orc,
	Vampire
};

class Creature : public Object
{
public:
	Creature( const sf::Vector2f & startPosition, CreatureType c );

	virtual void Update();
	virtual void Draw();
	virtual void Damage( int d );

	virtual void SetHealth(int s1, int s2 );
	int GetCurrentStrength();


protected:
	sf::String name;
	sf::String weakness;
	
	sf::String str1;
	sf::String str2;
	int inStrength;
	int curStrength;
	const char * strengthValues;
	std::vector<Creature> list;
	bool view;
	bool dead;
	CreatureType creatureType;
	sf::Text type;
	sf::Text health;
	sf::Font font;
};

#endif