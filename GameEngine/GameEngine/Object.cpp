#include "Object.h"
#include "SFMLGame.h"
#include "ContentManager.h"
#include <cmath>
#include <math.h>


Object::Object( const sf::String & resourceName,
				const sf::String & resourceFile,
				const sf::Vector2f & startingPosition,
				int horizontalFrames,
				int verticalFrames )
		: sprite( new sf::Sprite ),
		  visible( true ),
		  horizontalAnimationFrames( horizontalFrames ),
		  verticalAnimationFrames( verticalFrames ),
		  totalAnimationFrames( horizontalFrames * verticalFrames ),
		  imageIndex( 0 ),
		  imageSpeed( 0 ),
		  previous( startingPosition ),
		  startPosition( startingPosition ),
		  velocity( 0, 0 ),
		  direction( 0 ),
		  friction( 0 ),
		  accel( 0, 0 )
{
	// set up the texture for the sprite
	ContentManager * manager = ContentManager::GetInstance();
	manager->Load<sf::Texture>(resourceName, resourceFile);
	sprite->setTexture( *manager->Find<sf::Texture>( resourceName ));
	// Position of the sprite in the "world"
	sprite->setPosition( startingPosition );
}

Object::~Object()
{
	delete sprite;
}

void Object::Update()
{
	SetImageIndex( ImageIndex() + ImageSpeed() );
	SetPosition( Position() + velocity );
	SetVelocity( Velocity() + accel );
	SetSpeed( std::max<float>( 0, Speed() - Friction() ) );
}

void Object::Draw()
{
	if( visible == true )
	{
		int xCoord = static_cast<int>( ImageIndex() ) % horizontalAnimationFrames;
		int yCoord = static_cast<int>( ImageIndex() ) / horizontalAnimationFrames;

		xCoord *= SpriteWidth();
		yCoord *= SpriteHeight();

		sprite->setTextureRect( sf::IntRect( xCoord, yCoord, SpriteWidth(), SpriteHeight() ) );
		SFMLGame::GetInstance()->GetWindow()->draw( *sprite );
	}
}

sf::Sprite * Object::GetSprite()
{
	return sprite;
}

#pragma region SpriteMove

sf::Vector2f Object::Position()
{
	return sprite->getPosition();
}

void Object::SetPosition( const sf::Vector2f & position )
{
	sprite->setPosition( position );
}

float Object::X()
{
	return sprite->getPosition().x;
}

void Object::SetX( float x )
{
	sprite->setPosition( x, sprite->getPosition().y );
}

float Object::Y()
{
	return sprite->getPosition().y;
}

void Object::SetY( float y )
{
	sprite->setPosition( sprite->getPosition().x, y );
}

sf::Vector2f Object::PreviousPosition()
{
	return previous;
}

void Object::SetPreviousPosition( const sf::Vector2f & position )
{
	previous = position;
}

float Object::XPrevious()
{
	return previous.x;
}

void Object::SetXPrevious( float x )
{
	SetPreviousPosition( sf::Vector2f( x, PreviousPosition().y ) );
}

float Object::YPrevious()
{
	return previous.y;
}

void Object::SetYPrevious( float y )
{
	SetPreviousPosition( sf::Vector2f( PreviousPosition().x, y ) );
}

sf::Vector2f Object::StartPosition()
{
	return startPosition;
}

void Object::SetStartPosition( const sf::Vector2f & position )
{
	startPosition = position;
}

float Object::XStart()
{
	return startPosition.x;
}

void Object::SetXStart( float x )
{
	startPosition.x = x;
}

float Object::YStart()
{
	return startPosition.y;
}

void Object::SetYStart( float y )
{
	startPosition.y = y;
}

// Change in speed effects hspeed/vspeed. Change in direction changes hspeed/vspeed.
// Change in hspeed or vspeed changes hspeed/vspeed/direction/speed. 

sf::Vector2f Object::Velocity()
{
	return velocity;
}

void Object::SetVelocity( const sf::Vector2f & newVelocity )
{
	velocity = newVelocity;
	direction = atan2( -velocity.y, velocity.x );
}

float Object::HSpeed()
{
	return velocity.x;
}

void Object::SetHSpeed( float hspeed )
{
	velocity.x = hspeed;
	direction = atan2( -velocity.y, velocity.x );
}

float Object::VSpeed()
{
	return velocity.y;
}

void Object::SetVSpeed( float vspeed )
{
	velocity.y = vspeed;
	direction = atan2( -velocity.y, velocity.x );
}

float Object::Direction()
{
	return direction * 180.0f / 3.1415926535897f;
}

void Object::SetDirection( float newDirection )
{
	direction = newDirection * 3.1415926535897f / 180.0f;

	float s = Speed();
	velocity.x = s * cos( direction );
	velocity.y = -s * sin( direction );
}

float Object::Speed()
{
	return sqrt( ( velocity.x * velocity.x ) + ( velocity.y * velocity.y ) );
}

void Object::SetSpeed( float newSpeed )
{
	float oldSpeed = Speed();

	if( oldSpeed == 0 )
	{
		velocity.x = newSpeed * cos( direction );
		velocity.y = -newSpeed * sin( direction );
	}
	else
	{
		velocity *= ( newSpeed / oldSpeed );
	}
}

float Object::Friction()
{
	return friction;
}

void Object::SetFriction( float newFriction )
{
	if( friction >= 0 )
		friction = newFriction;
	else if( friction < 0 )
		friction = 0;
}

sf::Vector2f Object::Acceleration()
{
	return accel;
}

void Object::SetAcceleration( const sf::Vector2f & acceleration )
{
	accel = acceleration;
}

float Object::HAcceleration()
{
	return accel.x;
}

void Object::SetHAcceleration( float hacceleration )
{
	accel.x = hacceleration;
}

float Object::VAcceleration()
{
	return accel.y;
}

void Object::SetVAcceleration( float vacceleration )
{
	accel.y = vacceleration;
}

void Object::MotionSet( float newDirection, float newSpeed )
{
	direction = newDirection * 3.1415926535897f / 180.0f;
	float dx = newSpeed * cos( direction );
	float dy = -newSpeed * sin( direction );
	velocity = sf::Vector2f( dx, dy );
}

void Object::MotionAdd( float newDirection, float newSpeed )
{
	direction = newDirection * 3.1415926535897f / 180.0f;
	float dx = newSpeed * cos( direction );
	float dy = -newSpeed * sin( direction );
	velocity += sf::Vector2f( dx, dy );
}

#pragma endregion

#pragma region SpriteFunc

bool Object::Visible()
{
	return visible;
}

void Object::SetVisible( bool isVisible )
{
	visible = isVisible;
}

int Object::SpriteWidth()
{
	// TO DO
	return sprite->getTexture()->getSize().x / horizontalAnimationFrames;
}

int Object::SpriteHeight()
{
	// TO DO
	return sprite->getTexture()->getSize().y / verticalAnimationFrames;
}

float Object::SpriteXOffset()
{
	return sprite->getOrigin().x;
}

void Object::SetSpriteXOffset( float x_offset )
{
	sprite->setOrigin( x_offset, SpriteYOffset() );
}

float Object::SpriteYOffset()
{
	return sprite->getOrigin().y;
}

void Object::SetSpriteYOffset( float y_offset )
{
	sprite->setOrigin( SpriteXOffset(), y_offset );
}

int Object::ImageNumber()
{
	return totalAnimationFrames;
}

float Object::ImageIndex()
{
	return imageIndex;
}

void Object::SetImageIndex( float index )
{
	imageIndex = static_cast<float>( fmod( index, ImageNumber() ) );	// Fmod returns the floating-point
	if( imageIndex < 0 )												// remainder of numer/denom (rounded
	{																	// towards zero).
		imageIndex += ImageNumber();
	}
}

float Object::ImageSpeed()
{
	return imageSpeed;
}

void Object::SetImageSpeed( float speed )
{
	imageSpeed = speed;
}

#pragma endregion