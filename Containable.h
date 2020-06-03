#pragma once

#include <list>

#include "Object.h"
#include "Item.h"

class Entity;

class Containable : public virtual Object
{
protected:
	list<Object*> objects; //can be item or entity

	static string FunctionTake(Object* me, Action action, Entity& actor, World& world);

	static string FunctionDrop(Object* me, Action action, Entity& actor, World& world);

public:

	Containable();

	void Add(Object* object);

	tuple<Object*, Object*> Search(string object) override;
};