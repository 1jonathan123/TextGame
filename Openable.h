#pragma once

#include <string>

#include "Object.h"

using namespace std;

enum State { Closed, Opened };

class Openable : virtual public Object
{
	State state;

	Object* key;

protected:

	static string FunctionOpen(Object* me, Action action, Entity& actor, World& world);

	static string FunctionClose(Object* me, Action action, Entity& actor, World& world);


public:

	Openable(Object* key = nullptr);

	State GetState();
};