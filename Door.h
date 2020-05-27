#pragma once

#include "Object.h"

enum DoorState { Close, Open };

class Door : Object
{
	DoorState state; //the state of the door
	Direction place; //the place of the door in the room(where it leads to)

public:

	Door(string name, string description);

	string Act(Action, Entity, World) override;
};