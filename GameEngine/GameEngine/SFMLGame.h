#ifndef SFMLGAME_H
#define SFMLGAME_H

#include <SFML/Graphics.hpp>
//#include "sfmlKeyboard.h"

class sfmlKeyboard;
class Scene;

class SFMLGame
{
public:
	// Get singleton object
	static SFMLGame * GetInstance();
	// Virtual destructor
	virtual ~SFMLGame();
	// Run the game loop
	virtual void Run( Scene * firstScene );
	// Get window object
	sf::RenderWindow * GetWindow();
	// Set title bar text
	void SetTitleBarText( const sf::String & text );
	// Update game
	virtual void Update();
	// Handle input 
	virtual void HandleEvents();
	// Draw game
	virtual void Draw();
	// Get fixed time step setting
	bool IsFixedTimeSteps();
	// Set fixed time step setting
	void SetFixedTimeSteps( bool isFixedTimeSteps );
	// Get the current scene
	Scene * GetCurrentScene();
	// Set the current scene
	void ChangeCurrentScene( Scene * newScene );
	// Exit the game by closing the game window
	void ExitGame();

private:
	// Constructor
	SFMLGame();
	// Pointer to the singleton object
	static SFMLGame * instance;
	// Window object
	sf::RenderWindow * window;
	// Wheteher or not to use fixed time steps
	bool useFixedTimeSteps;
	// Milliseconds per game frame
	sf::Time timePerGameFrame;
	// create keyboard object
	sfmlKeyboard * kBoard;
	// Pointer to scene
	Scene * currentScene;
	// Pointer to new scene
	Scene * newScene;
	// Must we change scenes?
	bool changeCurrentScene;

	int frameCounter;
};

#endif