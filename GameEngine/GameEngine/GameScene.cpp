#include "GameBoard.h"
#include "GameScene.h"
#include "SFMLGame.h"
#include "PlayerLabel.h"
#include "Treasure.h"
#include "Background.h"

GameScene::GameScene( std::vector<sf::String> names, int num )
	: Scene()
{
	playerList.swap( names );
	numPlayers = num;

	Background * b = new Background( sf::Vector2f( 0,0 ) );
	InstanceCreate( b );

	for( int i = 0; i < playerList.size(); ++i )
	{
		float x = ( 1560 / numPlayers ) * ( i % numPlayers );
		players.push_back( new PlayerLabel( sf::Vector2f( x + ( 500 / numPlayers ) -
			( numPlayers * 15 ), 725 ), playerList[i] ) );
		InstanceCreate( players[i] );
	}

	gameboard = new GameBoard( playerList, numPlayers, &GameScene::AddTreasure );
	InstanceCreate( gameboard );

	currentPlayer = players.begin();
	previousPlayer = players.end() - 1;
	(*currentPlayer)->SetCurrentlyPlaying(true);
}

void GameScene::Update()
{
	Scene::Update();

	(*currentPlayer)->Update();

	gameboard->Update();
}

void GameScene::Draw()
{
	Scene::Draw();

	(*currentPlayer)->Draw();

	gameboard->Draw();
}

void GameScene::AddTreasure( Treasure * t, bool nextTurn )
{
	if( nextTurn == true )
	{
		IncrementTurn();
	} 
	// Add treasure from GameRoom to player
	else if( nextTurn == false)
	{
		(*previousPlayer)->AddTreasure( t );
	}
}

void GameScene::IncrementTurn()
{
	(*currentPlayer)->SetCurrentlyPlaying(false);

	++currentPlayer;
	++previousPlayer;

	if( currentPlayer == players.end() )
		currentPlayer = players.begin();

	if( previousPlayer == players.end() )
		previousPlayer = players.begin();

	(*currentPlayer)->SetCurrentlyPlaying(true);
}