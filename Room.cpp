#include "Room.h"

Room::Room(string name, string description, Room* nearby[DIRECTIONS_NUMBER], Door* doors[DIRECTIONS_NUMBER]) : Object(name, description)
{
	for (int i = 0; i < DIRECTIONS_NUMBER; ++i)
	{
		this->nearby[i] = nearby[i];
		this->doors[i] = doors[i];
	}

	visited = false;
}

string Room::Act(Action action, Entity actor, World world)
{
	switch (action.id)
	{
	case Enter:
		if (!visited)
			return description;
		break;

	case Move:

		if (nearby[action.direction])
		{
			objects.remove(&actor);

			nearby[action.direction]->objects.push_back(&actor);

			return nearby[action.direction]->Act(Action(Enter), actor, world);
		}

		if (doors[action.direction])
		{
			if (doors[action.direction]->GetState() == Open)
			{
				objects.remove(&actor);

				doors[action.direction]->GetTarget()->objects.push_back(&actor);

				return doors[action.direction]->GetTarget()->Act(Action(Enter), actor, world);
			}

			return "The " + doors[action.direction]->GetName() + " is close.";
		}

		return "You can't move to this direction."; //since there is not a door or passage to there

	default:
		return Object::Act(action, actor, world);
	}
}