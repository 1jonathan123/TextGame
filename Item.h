#pragma once

#include "Object.h"

class Item : public Object
{
public:

	string Act(Action, Entity, World) override;
};