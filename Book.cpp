#include "Book.h"

string Book::FunctionRead(Object* me, Action action, Entity& actor, World& world)
{
	Book* _this = dynamic_cast<Book*>(me);

	return _this->content;
}

Book::Book(string name, string description, string content, bool portable)
	: Item(name, description, portable)
{
	this->content = content;

	actions[Read] = &FunctionRead;
}