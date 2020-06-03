#include "Item.h"
#include "Entity.h"

Item::Item(string name, string description, bool portable)
	: Object(name, description)
{
	this->portable = portable;

	actions[Take] = &FunctionTake;
}

bool Item::IsPortable()
{
	return portable;
}

string Item::FunctionTake(Object* me, Action action, Entity& actor, World& world)
{
	return action.object->Act(Action(Take, action.direction, me), actor, world);
}
