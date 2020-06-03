#pragma once

#include "Object.h"
#include "Entity.h"
#include "Room.h"

#include <tuple>

//turning a string into formal command
//string is for errors
tuple<Object*, Action, string> Interpret(string command, Entity& actor, World& world);