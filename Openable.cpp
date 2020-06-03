#include "Openable.h"
#include "Room.h"

Openable::Openable(Object* key)
{
	this->key = key;

	state = Closed;

	actions[Open] = &FunctionOpen;
	actions[Close] = &FunctionClose;

	string b = name;
}

string Openable::FunctionOpen(Object* me, Action action, Entity& actor, World& world)
{
	Openable* _this = dynamic_cast<Openable*>(me);

	if (_this->state == Opened)
		return "It's already opened.";

	if (_this->key && action.object != _this->key)
	{
		if (dynamic_cast<Room*>(action.object))
			return "It looks like you need a key to open it.";
		else
			return "It's not the correct key.";
	}

	_this->state = Opened;
	return "It's opened now.";
}

string Openable::FunctionClose(Object* me, Action action, Entity& actor, World& world)
{
	Openable* _this = dynamic_cast<Openable*>(me);

	if (_this->state == Closed)
		return "It's already closed.";

	_this->state = Closed;
	return "It's closed now.";
}

State Openable::GetState()
{
	return state;
}