#pragma once

#include "Room.h"
#include "Entity.h"
#include "Openable.h"
#include "Placeable.h"

class Door : public Openable, public Placeable
{
	Room* target;

public:

	Door(string name, string description, Room* room, Room* target, Object* key);

	Room* GetTarget();
};