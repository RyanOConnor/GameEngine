#include "EnterPlayerScene.h"
#include "SFMLGame.h"
#include "EnterPlayerMenu.h"
#include "Button.h"
#include "GameScene.h"
#include "PlayerList.h"
#include "Background.h"

void StartGame();

std::vector<sf::String> playerNames;
int numberOfPlayers;

EnterPlayerScene::EnterPlayerScene( std::vector<sf::String> pNames, int players, int key )
	: Scene()
{
	names = pNames;
	numPlayers = players;
	int currentPlayer = names.size() + 1;

	Background * b = new Background( sf::Vector2f(0,0) );
	InstanceCreate(b);

	if( names.size() >= numPlayers )
	{
		playerNames = names;
		numberOfPlayers = numPlayers;
		Button * button = new Button( sf::Vector2f(600, 200), StartGame, "Dungeon" );
		InstanceCreate( button );
	}
	else
	{
		EnterPlayerMenu * menu = new EnterPlayerMenu( sf::Vector2f( 300, 200 ), currentPlayer, 
			&EnterPlayerScene::EnterKeyPressed, "Enter Player ", key );
		InstanceCreate( menu );
	}
	PlayerList * list = new PlayerList( names, players );
	InstanceCreate( list );
}


void EnterPlayerScene::EnterKeyPressed( sf::String name, int key )
{
	if( names.size() >= numPlayers )
	{
		SFMLGame::GetInstance()->ChangeCurrentScene( new EnterPlayerScene( names, numPlayers, key ) );
	}
	else
	{
		names.push_back(name);
		SFMLGame::GetInstance()->ChangeCurrentScene( new EnterPlayerScene( names, numPlayers, key ) );
	}
}

void StartGame()
{
	// TODO: Change to Gameboard scene WITH PlayerList

	SFMLGame::GetInstance()->ChangeCurrentScene( new GameScene( playerNames, numberOfPlayers ) );
}