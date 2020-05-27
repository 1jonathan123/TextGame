#include "Object.h"

Object::Object(string name, string description)
{
	this->name = name;
	this->description = description;
}

string Object::Act(Action action, Entity actor, World world)
{
	switch (action.id)
	{
	case Examine:
		return description;
	}

	return "It's simply impossible."; //wrong action on this object
}

string Object::GetName()
{
	return name;
}
