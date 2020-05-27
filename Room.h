#pragma once

#include "Object.h"
#include "Door.h"
#include <list>

class Room : public Object
{
	Room* nearby[DIRECTIONS_NUMBER]; //if room[NORTH] is not null then there is passage to the north
	Door* doors[DIRECTIONS_NUMBER]; //same, just with doors

	list<Object*> objects; //can be item or entity

	bool visited; //the room will write it's description when the player enters for the first time

public:

	Room(string name, string description, Room* nearby[DIRECTIONS_NUMBER], Door* doors[DIRECTIONS_NUMBER]);

	string Act(Action, Entity, World) override;
};