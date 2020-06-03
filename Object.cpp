#include "Object.h"
#include "Entity.h"

Object::Object(string name, string description)
{
	if (name == "")
		name = name;

	this->name = name;
	this->description = description;

	for (int i = 0; i < ACTIONS_NUMBER; ++i)
		actions[i] = nullptr;

	actions[Examine] = &FunctionExamine;
}

string Object::FunctionExamine(Object* object, Action action, Entity& actor, World& world)
{
	return object->description;
}

string Object::Act(Action action, Entity& actor, World& world)
{
	if (actions[action.id])
		return (actions[action.id])(this, action, actor, world);

	return "It's simply impossible."; //wrong action on this object
}

tuple<Object*, Object *> Object::Search(string object)
{
	if (name.find(object) != string::npos)
		return tuple<Object*, Object*>(this, this);

	return tuple<Object*, Object*>(nullptr, nullptr);
}

string Object::GetName()
{
	return name;
}
