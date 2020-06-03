#include "Constants.h"

string ToString(Direction direction)
{
	return StringDirection[direction];
}

Direction ToDirection(string direction)
{
	for (int i = 0; i < DIRECTIONS_NUMBER; ++i)
		if (direction == StringDirection[i])
			return (Direction)i;

	return Nowhere;
}

ActionID ToAction(string action)
{
	for (int i = 0; i < ACTIONS_NUMBER; ++i)
		if (action == StringAction[i])
			return (ActionID)i;

	return UnknownAction;
}

string AddA(string something)
{
	int t = AEIOU.find(something[0]);

	if (t >= 0)
		return "an " + something;

	return "a " + something;
}
