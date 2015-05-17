#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Object.h"
#include <vector>

class GameBoardRoom;
class PlayerLabel;
class Treasure;
class GameScene;

class GameBoard : public Object
{
public:
	typedef void (GameScene::*CallBackType)( Treasure *, bool );

	GameBoard( std::vector<sf::String> players,
				int numPlayers,
				CallBackType tAdd,
				int rooms = 20 );

	virtual void Update();
	virtual void Draw();


private:
	CallBackType AddTreasure;

	std::vector<GameBoardRoom *> rooms;
	std::vector<PlayerLabel *> players;

	std::vector<sf::String> playerList;
	int numberOfPlayers;

};

#endif