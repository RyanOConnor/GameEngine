#include "Object.h"
#include "Scene.h"

Scene::Scene()
	: objects()
{
	// Nothing here... yet.
}

Scene::~Scene()
{
	std::vector<Object *>::iterator iter;
	for( iter = objects.begin(); iter != objects.end(); ++iter)
	{
		delete (*iter);
	}
}

void Scene::Update()
{
	std::vector<Object *>::iterator iter;
	for( iter = objects.begin(); iter != objects.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void Scene::Draw()
{
	std::vector<Object *>::iterator iter;
	for( iter = objects.begin(); iter != objects.end(); ++iter)
	{
		(*iter)->Draw();
	}
}

void Scene::InstanceCreate( Object * newObject )
{
	objects.push_back( newObject );
}