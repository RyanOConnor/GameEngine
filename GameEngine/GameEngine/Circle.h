#ifndef CIRCLE_H
#define CIRCLE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Circle : public Object
{
public:
	// constructor
	Circle( const sf::Vector2f & startingPosition );
	// update the movement
	virtual void Update();

};

#endif