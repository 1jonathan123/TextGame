#pragma once

#include "Object.h"
#include "Room.h"

enum DoorState { Close, Open };

class Door : public Object
{
	DoorState state; //the state of the door
	Direction place; //the place of the door in the room(where it leads to)
	Room* target;

public:

	Door(string name, string description);

	DoorState GetState();

	Room* GetTarget();

	string Act(Action, Entity, World) override;
};