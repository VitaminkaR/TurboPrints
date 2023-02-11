#pragma once

#include "platform.h"
#include "InputBox.h"
#include "OperationBlocks/CreateOperationBlock.h"

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
	std::string name;
	InputBox* inputs[3];
};

std::string get_string_vartype(VarType vt);
VarType get_vartype_string(std::string &str);