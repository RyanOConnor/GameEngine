#include <string>
#include "ContentManager.h"
#include "GameConfiguration.h"
#include "SFMLGame.h"
#include "sfmlKeyboard.h"
#include "Scene.h"

// Initialize all static variables
SFMLGame * SFMLGame::instance = 0;

// Constructor
SFMLGame::SFMLGame( )
	: window( new sf::RenderWindow( sf::VideoMode( GameConfiguration::DEFAULT_SCREEN_WIDTH, GameConfiguration::DEFAULT_SCREEN_HEIGHT ), GameConfiguration::DEFAULT_TITLE_BAR_TEXT ) ),
	  useFixedTimeSteps( true ),
	  timePerGameFrame( sf::milliseconds( 1000 / GameConfiguration::DEFAULT_FRAME_RATE ) ),
	  kBoard( new sfmlKeyboard ),
	  currentScene( 0 ),
	  newScene( 0 ),
	  changeCurrentScene( false )
{
	// Nothing here...
	frameCounter = 0;
}

// Destructor
SFMLGame::~SFMLGame()
{
	delete window;
	delete instance;
	delete kBoard;
	delete currentScene;
}

// Get singleton object
SFMLGame * SFMLGame::GetInstance()
{
	if( instance == 0 )
	{
		instance = new SFMLGame();
	}
	return instance;
}

void SFMLGame::SetTitleBarText( const sf::String & text )
{
	window->setTitle( text );
}

sf::RenderWindow * SFMLGame::GetWindow()
{
	return GetInstance()->window;
}

void SFMLGame::ExitGame()
{
	window->close();
}

void SFMLGame::Run( Scene * firstScene )
{
	currentScene = firstScene;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window->isOpen())
    {
		HandleEvents();
		timeSinceLastUpdate += clock.restart();
		if( ( timeSinceLastUpdate > timePerGameFrame ) ||  ( useFixedTimeSteps == false ) )
		{
			timeSinceLastUpdate = sf::Time::Zero;
			Update();
			Draw();
			++frameCounter;
		}
    }
}

void SFMLGame::Update()
{
	//Update the keyboard buffers
	kBoard->Update();
	if( currentScene != 0 )
	{
		newScene = 0;
		changeCurrentScene = false;

		currentScene->Update();
		
		if( changeCurrentScene == true )
		{
			delete currentScene;
			currentScene = newScene;
		}
	}
}

void SFMLGame::HandleEvents()
{
    sf::Event event;

    while( window->pollEvent( event ) )
    {
		if( event.type == sf::Event::KeyPressed )
		{
			kBoard->HandleEvents( event.key.code, true );
		}
		if( event.type == sf::Event::KeyReleased )
		{
			kBoard->HandleEvents( event.key.code, false );
		}
        if( event.type == sf::Event::Closed )
		{
            window->close();
		}
    }
}

void SFMLGame::Draw()
{
    window->clear();

	if( currentScene != 0 )
	{
		currentScene->Draw();
	}

	window->display();
}

bool SFMLGame::IsFixedTimeSteps()
{
	return useFixedTimeSteps;
}

void SFMLGame::SetFixedTimeSteps( bool isFixedTimeSteps )
{
	useFixedTimeSteps = isFixedTimeSteps;
}

Scene * SFMLGame::GetCurrentScene()
{
	return currentScene;
}

void SFMLGame::ChangeCurrentScene( Scene * nextScene )
{
	changeCurrentScene = true;
	
	// TODO: Fix it up so it doesn't delete pointers to the same next scene
	if ( newScene != 0 )
	{
		delete newScene;
	}

	newScene = nextScene;
}