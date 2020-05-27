#include "Action.h"

Action::Action(ActionID id, Direction direction = Nowhere, Object* object = nullptr)
{
	this->id = id;
	this->direction = direction;
	this->object = object;
}
