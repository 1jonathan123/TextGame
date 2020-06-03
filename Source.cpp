#include <iostream>
#include <string>
#include <windows.h>

#include "World.h"

using namespace std;

int main()
{
	/*string a;

	getline(cin, a);

	if (a.find("with") >= 0)
	{
		int b = a.find(' ');
		int c = a.find("with");

		string action = a.substr(0, a.find(' '));
		string item1 = a.substr(a.find(' ') + 1, a.find("with") - (a.find(' ') + 2));
		string item2 = a.substr(a.find("with") + 5);
	}
	else
	{

	}*/

	World world = World();

	world.WriteOutput(world.ExecuteCommand("enter"));

	while (true)
	{
		world.WriteOutput(world.ExecuteCommand(world.GetInput()));
	}

	return 0;
}