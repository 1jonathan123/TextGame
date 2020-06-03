#pragma once

#include <list>

#include "Item.h"

class Report : public Item
{
	string* sections;
	string* values;

	int length; //sections number

protected:

	static string FunctionRead(Object* me, Action action, Entity& actor, World& world);

	static string FunctionWrite(Object* me, Action action, Entity& actor, World& world);

public:

	Report(string name, string description, string* sections, int length);

	~Report();
};