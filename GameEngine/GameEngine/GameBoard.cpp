#include "GameBoard.h"
#include "GameBoardRoom.h"
#include "PlayerList.h"
#include "GameScene.h"
#include "SFMLGame.h"
#include "Scene.h"
#include "Treasure.h"

void PassTreasure( Treasure * t, bool b );

GameBoard::GameBoard( std::vector<sf::String> names,
					 int numPlayers,
					 CallBackType tAdd,
					 int numberOfRooms )
	: Object( "space", "button.png", sf::Vector2f( 0, 0 ), 3, 1 ),
	  AddTreasure( tAdd )
{
	playerList.swap( names );
	numberOfPlayers = numPlayers;
	
	srand(time(NULL));
	for( int i=0; i < numberOfRooms; ++i)
	{
		float x = 320 * ( i % 5 );
		float y = 160 * ( i / 5 );
		rooms.push_back( new GameBoardRoom( sf::Vector2f( x + 5, y + 5 ), rand() % 5, PassTreasure ) );
	}
}

void GameBoard::Update()
{
	std::vector<GameBoardRoom *>::iterator iter;
	for( iter = rooms.begin(); iter != rooms.end(); ++iter)
	{
		(*iter)->Update();
	}
	std::vector<PlayerLabel *>::iterator iterP;
	for( iterP = players.begin(); iterP != players.end(); ++iterP)
	{
		(*iterP)->Update();
	}
}

void GameBoard::Draw()
{
	if( visible == true )
	{
		std::vector<GameBoardRoom *>::iterator iter;
		for( iter = rooms.begin(); iter != rooms.end(); ++iter)
		{
			(*iter)->Draw();
		}
		std::vector<PlayerLabel *>::iterator iterP;
		for( iterP = players.begin(); iterP != players.end(); ++iterP)
		{
			(*iterP)->Draw();
		}
	}
}

void PassTreasure( Treasure * t, bool nextTurn )
{
	// Pass treasure to GameScene::AddTreasure
	Scene * scene = SFMLGame::GetInstance()->GetCurrentScene();
	GameScene * g = dynamic_cast<GameScene *>(scene);
	g->AddTreasure( t, nextTurn );
}