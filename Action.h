#pragma once

#include "Object.h"

class Object;

//contains useful information about an action
struct Action
{
	ActionID id;

	Direction direction; //the direction of the action - for example, "move north"

	Object* object; //another parameter. Example: put x in y. here x is object

	Action(ActionID id = UnknownAction, Direction direction = Nowhere, Object* object = nullptr);
};