#ifndef SCENE_H
#define SCENE_H

#include <vector>

class Object;

class Scene
{
public:
	// constructor
	Scene();
	// destructor
	virtual ~Scene();

	virtual void Update();

	virtual void Draw();

	virtual void InstanceCreate( Object * newObject );

private:
	std::vector<Object *> objects;
};

#endif