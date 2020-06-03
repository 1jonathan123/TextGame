#include "Action.h"

Action::Action(ActionID id, Direction direction, Object* object)
{
	this->id = id;
	this->direction = direction;
	this->object = object;
}
