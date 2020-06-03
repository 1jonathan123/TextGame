#include <string>
#include <iostream>
#include <Windows.h>

#include "Constants.h"
#include "Entity.h"
#include "Door.h"
#include "Room.h"
#include "Box.h"
#include "Book.h"
#include "Report.h"

class Entity;

using namespace std;

#pragma once
class World
{
	HANDLE hConsole;

	Room* startRoom;
	Room* anotherRoom;

	Door* door;

	Entity* player;

	Box* box;

	Item* key;

	Book* note;

	Report* report;

public:
	World();

	//execute a command that the user(or any other entity) entered
	string ExecuteCommand(string command);

	string GetInput();

	void WriteOutput(string output);
};