#include "Item.h"

string Item::Act(Action action, Entity actor, World world)
{
	switch (action.id)
	{
	default:
		return Object::Act(action, actor, world);
	}
}
