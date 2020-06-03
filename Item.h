#pragma once

#include "Object.h"

class Entity;

class Item : public Object
{
	bool portable;

protected:

	static string FunctionTake(Object* me, Action action, Entity& actor, World& world); //TOCHANGE

public:

	Item(string name, string description, bool portable);

	bool IsPortable();
};