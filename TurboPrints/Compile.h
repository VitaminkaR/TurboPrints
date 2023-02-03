#pragma once

#include "platform.h"

void compile();

enum VarType
{
	INT,
	SHORT,
	BYTE,
	ARRAY,			// массив int типа		(name dd ...)
	STRING			// массив byte типа	(name db ...)
};

struct Var
{
	VarType var_type;
	std::string value;
};