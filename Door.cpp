#include "Door.h"

Door::Door(string name, string description) : Object(name, description)
{
	
}

DoorState Door::GetState()
{
	return state;
}

Room* Door::GetTarget()
{
	return target;
}

string Door::Act(Action action, Entity actor, World world)
{
	switch (action)
	{
	default:
		return Object::Act(action, actor, world);
	}
}
