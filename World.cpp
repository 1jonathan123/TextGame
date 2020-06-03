#include "World.h"

World::World()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	startRoom = new Room("A room", "This is the first room.");

	anotherRoom = new Room("Another Room", "This is the second room.");

	key = new Item("iron key", "It's a simple iron key.", true);
	startRoom->Add(key);

	door = new Door("wooden door", "It's a simple wooden door.", startRoom, anotherRoom, key);

	startRoom->doors[North] = door;
	startRoom->Add(door);

	anotherRoom->doors[South] = door;
	anotherRoom->Add(door);

	note = new Book("note", "It's a note, which was written on a paper.", "Welcome to the lab.");

	box = new Box("wooden box", "It's an ancient wooden box.");
	box->Add(note);
	anotherRoom->Add(box);

	string sections[2] = { "This place is a", "The killer is" };
	report = new Report("report_1", "It's a standard report paper.", sections, 2);
	startRoom->Add(report);

	player = new Entity("me", "It's simply you.", startRoom);
	startRoom->Add(player);
}

string World::ExecuteCommand(string command)
{
	return player->ExecuteCommand(command, *this);
}

string World::GetInput()
{
	SetConsoleTextAttribute(hConsole, 15);

	cout << "> ";

	string str;
	getline(cin, str);

	return str;
}

void World::WriteOutput(string output)
{
	SetConsoleTextAttribute(hConsole, 9);

	cout << output << "\n";
}
