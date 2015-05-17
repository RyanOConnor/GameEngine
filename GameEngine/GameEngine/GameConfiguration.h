#ifndef GAMECONFIGURATION_H
#define GAMECONFIGURATION_H

#include <SFML/Graphics.hpp>

class GameConfiguration
{
public:
	static unsigned int DEFAULT_SCREEN_WIDTH;
	static unsigned int DEFAULT_SCREEN_HEIGHT;
	static sf::String DEFAULT_TITLE_BAR_TEXT;
	static unsigned int DEFAULT_FRAME_RATE;
};

#endif