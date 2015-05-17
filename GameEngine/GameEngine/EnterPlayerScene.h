#ifndef ENTERPLAYERSCENE_H
#define ENTERPLAYERSCENE_H

#include "Scene.h"
#include "PlayerList.h"
#include <SFML/Graphics.hpp>

class EnterPlayerScene : public Scene
{
public:
	EnterPlayerScene( std::vector<sf::String> pNames, int players, int key = 0 );

	void EnterKeyPressed( sf::String names, int key );

private:
	std::vector<sf::String> names;
	int numPlayers;
};

#endif