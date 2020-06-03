#pragma once

#include <string>
using namespace std;

//Nowhere does not count! and it must be last
#define DIRECTIONS_NUMBER 4

enum Direction { North, South, West, East, Nowhere };
const string StringDirection[] = { "north", "south", "west", "east", "nowhere" };


string ToString(Direction direction);
Direction ToDirection(string direction);

#define ACTIONS_NUMBER 9

enum ActionID { Examine, Enter, Open, Close, Go, Take, Drop, Read, Write, UnknownAction };
const string StringAction[] = { "examine", "enter", "open", "close", "go", "take", "drop", "read", "write" };

ActionID ToAction(string action);

#define CONNECTING_WORDS_LENGTH 2
const string ConnectingWords[] = { "with", "from" };

const string AEIOU = "aeiou";

string AddA(string something);