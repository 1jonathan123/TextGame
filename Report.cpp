#include "Report.h"
#include "World.h"

string Report::FunctionRead(Object* me, Action action, Entity& actor, World& world)
{
	Report* _this = dynamic_cast<Report*>(me);

	string result = "";

	for (int i = 0; i < _this->length; ++i)
		result += to_string(i + 1) + ") " + _this->sections[i] + +": " + _this->values[i] + (i + 1 != _this->length ? "\n" : "");

	return result;
}

string Report::FunctionWrite(Object* me, Action action, Entity& actor, World& world)
{
	Report* _this = dynamic_cast<Report*>(me);

	world.WriteOutput("To which line of the report you want to write? (Zero to cancel)");

	int line = atoi(world.GetInput().c_str());

	if (line == 0)
		return "Canceled.";

	if (line - 1 < 0 || line - 1 >= _this->length)
		return "Illegal line.";

	world.WriteOutput("What do you want to write?");

	_this->values[line - 1] = world.GetInput();

	return "Done.";
}

Report::Report(string name, string description, string* sections, int length)
	: Item(name, description, true)
{
	actions[Read] = &FunctionRead;
	actions[Write] = &FunctionWrite;

	this->sections = new string[length];
	this->values = new string[length];

	for (int i = 0; i < length; ++i)
		this->sections[i] = sections[i];

	this->length = length;
}

Report::~Report()
{
	delete[] sections;
	delete[] values;
}
