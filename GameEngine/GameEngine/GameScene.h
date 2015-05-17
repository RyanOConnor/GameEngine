#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class PlayerLabel;
class GameBoard;
class Treasure;

class GameScene : public Scene
{
public:
	GameScene( std::vector<sf::String> names, int numPlayers );

	void Update();
	void Draw();

	void AddTreasure( Treasure * t, bool nextTurn );
	void IncrementTurn();

private:
	std::vector<PlayerLabel *> players;
	GameBoard * gameboard;

	std::vector<sf::String> playerList;

	int numPlayers;
	bool nextTurn;
	std::vector<PlayerLabel *>::iterator currentPlayer;
	std::vector<PlayerLabel *>::iterator previousPlayer;
};

#endif