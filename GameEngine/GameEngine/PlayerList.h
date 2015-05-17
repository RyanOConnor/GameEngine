#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include "Object.h"
#include <vector>
#include "PlayerLabel.h"

class GameScene;

class PlayerList : public Object
{
public:
	PlayerList( std::vector<sf::String> names, 
				int numPlayers );

	virtual void Update();
	virtual void Draw();

	void LabelToList();

	std::vector<PlayerLabel *> labels;

private:
	sf::String points;
};


#endif