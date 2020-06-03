#pragma once

#include "Object.h"

class Room;

class Placeable : virtual public Object
{
public:
	Placeable(Room* room = nullptr);

	Room* room;
};