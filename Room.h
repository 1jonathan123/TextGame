#pragma once

#include <list>

#include "Object.h"
#include "Door.h"
#include "Item.h"
#include "Containable.h"

class Door;
class Object;

class Room : public virtual Containable
{
	bool visited; //the room will write it's description when the player enters for the first time

	void Transport(Entity& entity, Room* newRoom);

protected:

	static string FunctionEnter(Object* me, Action action, Entity& actor, World& world);

	static string FunctionExamine(Object* me, Action action, Entity& actor, World& world);

	static string FunctionGo(Object* me, Action action, Entity& actor, World& world);

public:

	Room* nearby[DIRECTIONS_NUMBER]; //if room[NORTH] is not null then there is passage to the north
	Door* doors[DIRECTIONS_NUMBER]; //same, just with doors

	Room(string name = "room", string description = "");
};