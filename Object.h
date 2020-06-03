#pragma once

#include <string>

#include "Constants.h"
#include "Action.h"

using namespace std;

struct Action;
class Entity;
class Room;
class World;

//abstract class for any object in the game
class Object
{
protected:

	string name; //the name of the object
	string description; //the description of the object(available with examine command)

	string(*actions[ACTIONS_NUMBER])(Object*, Action, Entity&, World&);

	static string FunctionExamine(Object* object, Action action, Entity& actor, World& world);

public:

	Object(string name = "object", string description = "");

	//an entity performs action on the object
	//returns the output of the action
	string Act(Action action, Entity& actor, World& world);

	//search object in the object(can be a room, a chest, whatever)
	//returns (found, in)
	virtual tuple<Object*, Object*> Search(string object);

	//returns name
	string GetName();
};