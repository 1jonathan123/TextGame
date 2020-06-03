#pragma once

#include "Openable.h"
#include "Containable.h"

class Box : public virtual Openable, public virtual Containable
{
protected:

	static string FunctionTake(Object* me, Action action, Entity& actor, World& world);

	static string FunctionExamine(Object* me, Action action, Entity& actor, World& world);

public:

	Box(string name, string description, Object* key = nullptr);
};