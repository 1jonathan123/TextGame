#pragma once

#include "Object.h"

enum ActionID { Examine, Enter, Open, Close, Move };

//contains useful information about an action
struct Action
{
	ActionID id;

	Direction direction; //the direction of the action - for example, "move north"

	Object* object; //another parameter. Example: put x in y. here x is object

	Action(ActionID id, Direction direction = Nowhere, Object* object = nullptr);
};