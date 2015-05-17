#include "SFMLGame.h"
#include "FirstScene.h"

void main()
{
	SFMLGame * game = SFMLGame::GetInstance();
	game->Run( new FirstScene() );
}