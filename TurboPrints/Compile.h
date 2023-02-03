#pragma once

#include "platform.h"

void compile();

enum VarType
{
	INT,
	SHORT,
	BYTE,
	ARRAY,			// ������ int ����		(name dd ...)
	STRING			// ������ byte ����	(name db ...)
};

struct Var
{
	VarType var_type;
	std::string value;
};