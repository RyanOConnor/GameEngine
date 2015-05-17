#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object( const sf::String & resourceName,
			const sf::String & resourceFile,
			const sf::Vector2f & startingPosition,
			int horizontalFrames = 1,				// Optional parameters. If not placed,
			int verticalFrames = 1 );				// default is set to 1.
	virtual ~Object();

	virtual void Update();
	virtual void Draw();

	bool Visible();
	void SetVisible( bool isVisible );

	int SpriteWidth();
	int SpriteHeight();

	float SpriteXOffset();
	void SetSpriteXOffset( float x_offset );

	float SpriteYOffset();
	void SetSpriteYOffset( float y_offset );

	float ImageIndex();
	void SetImageIndex( float index );

	float ImageSpeed();
	void SetImageSpeed( float speed );

	int ImageNumber();

	sf::Sprite * GetSprite();


	// BEGIN HOMEWORK ASSIGNMENT
	sf::Vector2f Position();
	void SetPosition( const sf::Vector2f & position );

	float X();
	void SetX( float x );

	float Y();
	void SetY( float Y );

	sf::Vector2f PreviousPosition();
	void SetPreviousPosition( const sf::Vector2f & position );

	float XPrevious();
	void SetXPrevious( float x );

	float YPrevious();
	void SetYPrevious( float Y );

	sf::Vector2f StartPosition();
	void SetStartPosition( const sf::Vector2f & position );

	float XStart();
	void SetXStart( float x );

	float YStart();
	void SetYStart( float Y );

	sf::Vector2f Velocity();
	void SetVelocity( const sf::Vector2f & velocity );

	float HSpeed();
	void SetHSpeed( float hspeed );

	float VSpeed();
	void SetVSpeed( float vspeed );

	float Direction();
	void SetDirection( float newDirection );

	float Speed();
	void SetSpeed( float speed );

	float Friction();
	void SetFriction( float friction );

	sf::Vector2f Acceleration();
	void SetAcceleration( const sf::Vector2f & acceleration );

	float HAcceleration();
	void SetHAcceleration( float hacceleration );

	float VAcceleration();
	void SetVAcceleration( float vacceleration );

	void MotionSet( float newDirection, float newSpeed );
	void MotionAdd( float newDirection, float newSpeed );
	// END HOMEWORK ASSIGNMENT


protected:
	sf::Sprite * sprite;

	sf::Vector2f previous;
	sf::Vector2f startPosition;
	sf::Vector2f velocity;
	sf::Vector2f accel;
	float direction; // in radians
	float friction;

		
	bool visible;

	int horizontalAnimationFrames;
	int verticalAnimationFrames;
	int totalAnimationFrames;

	float imageIndex;
	float imageSpeed;
};

#endif