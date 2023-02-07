#include "Compile.h"

std::vector<Var> vars;
std::string stack_size = "32";
BeginOE* start_point;

void compile()
{
	std::cout << "Start compile" << std::endl;

	std::ofstream out;          // поток для записи
	out.open("./out.asm"); // окрываем файл для записи
	if (out.is_open())
	{
		out << ";CREATED BY TURBOPRINTS\n\n";
	}
	std::string error;

	// компиляция
	// создание стэка
	out << "stack_segment segment stack \"stack\"\n";
	out << "\tdb " + stack_size + " DUP(0)\n";
	out << "stack_segment ends\n\n";
	// компиляция data segment
	out << "data_segment segment\n";
	for (int i = 0; i < vars.size(); i++)
	{
		out << '\t' << vars[i].name << " ";
		switch (vars[i].var_type)
		{
		case INT:
			out << "dd " << (vars[i].value == "") ? "?" : vars[i].value;
			break;
		case SHORT:
			out << "dw " << (vars[i].value == "") ? "?" : vars[i].value;
			break;
		case BYTE:
			out << "db " << (vars[i].value == "") ? "?" : vars[i].value;
			break;
		case ARRAY:
			out << "dd " << vars[i].value;
			break;
		case STRING:
			out << "db '" << vars[i].value << "'";
			break;
		}
		out << std::endl;
	}
	out << "data_segment ends\n\n";
	// компиляция кода
	out << "code_segment segment\n";
	out << "assume ss:stack_segment, ds:data_segment, cs:code_segment\n";
	out << "begin:\n";

	out << "code_segment ends\n";
	out << "end begin";

	if (error != "")
		std::cout << "ERROR " + error << std::endl;
	else
		std::cout << "COMPILE SUCCESS\n";

	out.close();
}

std::string get_string_vartype(VarType vt)
{
	switch (vt)
	{
	case INT:
		return "INT";
		break;
	case SHORT:
		return "SHORT INT";
		break;
	case BYTE:
		return "BYTE";
		break;
	case ARRAY:
		return "ARRAY";
		break;
	case STRING:
		return "STRING";
		break;
	default:
		return "NONE";
		break;
	}
}

VarType get_vartype_string(std::string &str)
{
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = (char)std::tolower(str[i]);
	}
	if(str == "int")
		return INT;
	else if(str == "short" || str == "shortint" || str == "short_int")
		return SHORT;
	else if(str == "array")
		return ARRAY;
	else if(str == "string" || str == "str")
		return STRING;
	else
		return BYTE;
}