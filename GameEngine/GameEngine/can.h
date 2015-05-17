#ifndef CAN_H
#define CAN_H

#include "Object.h"

class Can : public Object
{
public:
	Can( const sf::String & resourceName,
		 const sf::String & resourceFile );

	virtual void Update();
};

#endif