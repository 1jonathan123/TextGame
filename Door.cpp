#include "Door.h"

Door::Door(string name, string description, Room* room, Room* target, Object* key)
	: Placeable(room), Openable(key), Object(name, description)
{
	this->target = target;
}

Room* Door::GetTarget()
{
	return target;
}