#include "Door.h"

Door::Door(string name, string description) : Object(name, description)
{
	
}

string Door::Act(Action action, Entity actor, World world)
{
	switch (action)
	{
	default:
		return Object::Act(action, actor, world);
	}
}
