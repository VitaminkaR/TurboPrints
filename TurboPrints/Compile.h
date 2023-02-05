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
	std::string name;
	SDL_Texture* texture[3];
};

std::string get_string_vartype(VarType vt);
VarType get_vartype_string(std::string &str);