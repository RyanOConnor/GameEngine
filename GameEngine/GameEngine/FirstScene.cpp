#include "FirstScene.h"
#include "EnterPlayerScene.h"
#include "Circle.h"
#include "Button.h"
#include "SFMLGame.h"
#include "Background.h"

void Button1Pressed();
void Button2Pressed();
void Button3Pressed();
void Button4Pressed();

FirstScene::FirstScene()
	: Scene()
{
	Background * b = new Background( sf::Vector2f(0,0) );
	InstanceCreate(b);

	Button * button = new Button( sf::Vector2f( 100, 100 ), Button1Pressed, "2 Players" );
	InstanceCreate( button );

	button = new Button( sf::Vector2f( 500, 100 ), Button2Pressed, "3 Players" );
	InstanceCreate( button );

	button = new Button( sf::Vector2f( 100, 500 ), Button3Pressed, "4 Players" );
	InstanceCreate( button );

	button = new Button( sf::Vector2f( 500, 500 ), Button4Pressed, "QUIT" );
	InstanceCreate( button );
}

void Button1Pressed()
{
	std::vector<sf::String> n;
	SFMLGame::GetInstance()->ChangeCurrentScene( new EnterPlayerScene(n, 2) );
}
void Button2Pressed()
{
	std::vector<sf::String> n;
	SFMLGame::GetInstance()->ChangeCurrentScene( new EnterPlayerScene(n, 3) );
}
void Button3Pressed()
{
	std::vector<sf::String> n;
	SFMLGame::GetInstance()->ChangeCurrentScene( new EnterPlayerScene(n, 4) );
}
void Button4Pressed()
{
	SFMLGame::GetInstance()->ExitGame();
}