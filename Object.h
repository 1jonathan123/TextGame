#pragma once

#include <string>

#include "World.h"
#include "Entity.h"
#include "Constants.h"
#include "Action.h"

using namespace std;

//abstract class for any object in the game
class Object
{
protected:

	string name; //the name of the object
	string description; //the description of the object(available with examine command)

public:
	
	Object(string name, string description);

	//an entity performs action on the object
	//returns the output of the action
	virtual string Act(Action action, Entity actor, World world);

	//returns name
	string GetName();
};