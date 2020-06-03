#pragma once

#include <list>

#include "Action.h"
#include "Interpret.h"
#include "Placeable.h"
#include "Containable.h"

using namespace std;

class Object;
class Item;
class Room;

class Entity : public Placeable, public Containable
{
public:

	Entity(string name = "entity", string description = "", Room* room = nullptr);

	//execute a command that the user(or any other entity) entered
	//this command is responsible to infer on which object the command should perform
	string ExecuteCommand(string command, World& world);
};