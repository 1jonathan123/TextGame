#include "Interpret.h"

//<action> <direction> (go north)
//<action> <object> (turn_on computer, attack scary_monster)
//<action> <object> with <item> (attack scary_monster with bow)
//<action> <object> to <item> (connect usb to computer)
tuple<Object*, Action, string> Interpret(string command, Entity& actor, World& world)
{
	Action action(UnknownAction, Nowhere, actor.room);
	Object* object = actor.room;

	string actionStr = command;
	string item1 = "";
	string item2 = "";

	int firstSpace = command.find(' ');

	int connectingWord = -1;
	int connectingWordLength = 0;

	for (int i = 0, t; i < CONNECTING_WORDS_LENGTH; ++i)
		if ((t = command.find(ConnectingWords[i])) >= 0)
		{
			if (connectingWord >= 0)
				return tuple<Object*, Action, string>
				(object, action, "Syntax error."); //too many connectors

			connectingWord = t;

			connectingWordLength = ConnectingWords[i].length();
		}

	if (connectingWord + connectingWordLength == command.length())
		return tuple<Object*, Action, string>
		(object, action, "Syntax error."); //connecting word cannot be the last

	if (firstSpace >= 0)
	{
		actionStr = command.substr(0, firstSpace);

		if (connectingWord >= 0)
		{
			item1 = command.substr(firstSpace + 1, connectingWord - firstSpace - 2);
			item2 = command.substr(connectingWord + connectingWordLength + 1);
		}
		else
			item1 = command.substr(firstSpace + 1);
	}

	action.id = ToAction(actionStr);
	if (action.id == UnknownAction)
		return tuple<Object*, Action, string>
		(object, action, "Unknown action '" + actionStr + "'.");

	if (item1 != "")
	{
		action.direction = ToDirection(item1);

		if (action.direction == Nowhere) //whoops, it wasn't a direction
		{
			tuple<Object*, Object*> t = actor.room->Search(item1);

			object = get<0>(t);

			action.object = get<1>(t);

			if (object == nullptr)
			{
				if (get<1>(t))
					return tuple<Object*, Action, string>
					(object, action, "Double meaning: '" + item1 + "'. Be more specific.");

				return tuple<Object*, Action, string>
					(object, action, "Unknown object '" + item1 + "'.");
			}
		}
	}

	if (item2 != "")
	{
		tuple<Object*, Object*> t = actor.Search(item2);

		action.object = get<0>(t);

		if (action.object == nullptr)
		{
			if (get<1>(t))
				return tuple<Object*, Action, string>
				(object, action, "Double meaning: '" + item2 + "'. Be more specific.");

			return tuple<Object*, Action, string>
				(object, action, "You don't have any '" + item2 + "'.");
		}
	}

	return tuple<Object*, Action, string>(object, action, "");
}