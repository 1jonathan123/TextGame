#include "Box.h"

Box::Box(string name, string description, Object* key)
	: Object(name, description), Openable(key)
{
	actions[Take] = FunctionTake;
	actions[Examine] = FunctionExamine;
}

string Box::FunctionTake(Object* me, Action action, Entity& actor, World& world)
{
	Box* _this = dynamic_cast<Box*>(me);

	if (_this->GetState() == Opened)
		return Containable::FunctionTake(me, action, actor, world);

	return "The " + me->GetName() + " is closed.";
}

string Box::FunctionExamine(Object* me, Action action, Entity& actor, World& world)
{
	Box* _this = dynamic_cast<Box*>(me);

	string desc = Containable::FunctionExamine(me, action, actor, world);

	if (_this->GetState() == Opened)
		for (auto i = _this->objects.begin(); i != _this->objects.end(); ++i)
			desc += "\nThere is " + AddA((*i)->GetName()) + " in the " + _this->GetName() + ".";

	return desc;
}
