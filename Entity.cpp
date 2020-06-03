#include "Entity.h"

Entity::Entity(string name, string description, Room* room)
	: Placeable(room), Object(name, description)
{
	
}

string Entity::ExecuteCommand(string command, World& world)
{
	tuple<Object*, Action, string> result = Interpret(command, *this, world);

	if (get<2>(result) == "") //no error
		return get<0>(result)->Act(get<1>(result), *this, world);
	
	return get<2>(result);
}