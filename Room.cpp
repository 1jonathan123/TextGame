#include "Room.h"

void Room::Transport(Entity& entity, Room* newRoom)
{
	entity.room = newRoom;
	objects.remove(&entity);
	newRoom->objects.push_back(&entity);
}

Room::Room(string name, string description)
	: Object(name, description)
{
	if (nearby == nullptr)
		return;

	for (int i = 0; i < DIRECTIONS_NUMBER; ++i)
	{
		nearby[i] = nullptr;
		doors[i] = nullptr;
	}

	visited = false;

	actions[Enter] = &FunctionEnter;
	actions[Examine] = &FunctionExamine;
	actions[Go] = &FunctionGo;
}

string Room::FunctionEnter(Object* me, Action action, Entity& actor, World& world)
{
	Room* _this = dynamic_cast<Room*>(me);

	if (!_this->visited)
	{
		_this->visited = true;
		return _this->Act(Action(Examine), actor, world);
	}

	return _this->name;
}

string Room::FunctionExamine(Object* me, Action action, Entity& actor, World& world)
{
	Room* _this = dynamic_cast<Room*>(me);

	string data = "\n";

	for (int i = 0; i < DIRECTIONS_NUMBER; ++i)
	{
		if (_this->nearby[i])
			data += "There is a passage leading " + ToString((Direction)i) + " here.\n";

		if (_this->doors[i])
			data += "There is " + AddA(_this->doors[i]->GetName()) + " leading " + ToString((Direction)i) + " here.\n";
	}

	for (list<Object*>::iterator i = _this->objects.begin(); i != _this->objects.end(); ++i)
		if (*i != &actor && !dynamic_cast<Door*>(*i))
			data += "There is " + AddA((*i)->GetName()) + " here.\n";

	return _this->name + "\n" + Object::FunctionExamine(me, action, actor, world) + data.substr(0, data.length() > 0 ? data.length() - 1 : 0);
}

string Room::FunctionGo(Object* me, Action action, Entity& actor, World& world)
{
	Room* _this = dynamic_cast<Room*>(me);

	if (action.direction == Nowhere)
		return "Where do you want to go?";

	if (_this->nearby[action.direction])
	{
		_this->objects.remove(&actor);

		_this->nearby[action.direction]->objects.push_back(&actor);

		actor.room = _this->nearby[action.direction];

		return _this->nearby[action.direction]->Act(Action(Enter), actor, world);
	}

	if (_this->doors[action.direction])
	{
		if (_this->doors[action.direction]->GetState() == Opened)
		{
			Room* target = actor.room == _this->doors[action.direction]->GetTarget() ? 
				_this->doors[action.direction]->room : _this->doors[action.direction]->GetTarget();

			_this->objects.remove(&actor);

			target->objects.push_back(&actor);

			actor.room = target;

			return target->Act(Action(Enter), actor, world);
		}

		return "The " + _this->doors[action.direction]->GetName() + " is close.";
	}

	return "You can't go to this direction."; //since there is not a door or passage to there
}