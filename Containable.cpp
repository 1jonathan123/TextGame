#include "Containable.h"

#include "Entity.h"

Containable::Containable()
{
	actions[Take] = &FunctionTake;
	actions[Drop] = &FunctionDrop;
}

void Containable::Add(Object* object)
{
	objects.push_back(object);
}

tuple<Object*, Object*> Containable::Search(string object)
{
	tuple<Object*, Object*> found = tuple<Object*, Object*>(nullptr, nullptr);

	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		if ((*i)->GetName().find(object) != string::npos)
		{
			if(get<0>(found) != nullptr)
				return tuple<Object*, Object*>(nullptr, this); //double meaning

			found = tuple<Object*, Object*>(*i, this);
		}
		else
		{
			tuple<Object*, Object*> t = (*i)->Search(object);

			if (get<0>(t))
			{
				if (get<0>(found) != nullptr)
					return tuple<Object*, Object*>(nullptr, this); //double meaning

				found = t;
			}
		}
	}

	if (get<0>(found) || get<1>(found)) //found or double meaning
		return found;

	return Object::Search(object);
}

string Containable::FunctionTake(Object* me, Action action, Entity& actor, World& world)
{
	Containable* _this = dynamic_cast<Containable*>(me);

	Item* item = dynamic_cast<Item*>(action.object);

	if (item && dynamic_cast<Entity*>(me))
	{
		if (&actor == me)
			return "You already have it.";

		return "It doesn't belong to you.";
	}

	if (item)
		if (item->IsPortable())
		{
			_this->objects.remove(item);
			actor.Add(item);
			return "Taken.";
		}

	return "It's not something you can take.";
}

string Containable::FunctionDrop(Object* me, Action action, Entity& actor, World& world)
{
	return string();
}
