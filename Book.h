#pragma once

#include "Item.h"

class Book : public Item
{
	string content;

protected:

	static string FunctionRead(Object* me, Action action, Entity& actor, World& world);

public:

	Book(string name, string description, string content, bool portable = true);
};