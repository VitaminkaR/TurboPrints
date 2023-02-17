#include "Compile.h"

std::vector<Var> vars;
std::string stack_size = "32";

extern std::vector<OperationBlock*> oelements;

void compile()
{
	std::cout << "Start compile" << std::endl;

	std::ofstream out;          
	out.open("./out.asm"); 
	if (out.is_open())
	{
		out << ";CREATED BY TURBOPRINTS\n\n";
	}
	std::string error;

	// ����������
	// �������� �����
	out << "stack_segment SEGMENT STACK \"stack\"\n";
	out << "\tDB " << stack_size << " DUP(0)\n";
	out << "stack_segment ENDS\n\n";
	// ���������� data segment
	out << "data_segment SEGMENT\n";
	for (int i = 0; i < vars.size(); i++)
	{
		out << '\t' << vars[i].name << " ";
		switch (vars[i].var_type)
		{
		case INT:
			out << "DD " << ((vars[i].value == "") ? "?" : vars[i].value);
			break;
		case SHORT:
			out << "DW " << ((vars[i].value == "") ? "?" : vars[i].value);
			break;
		case BYTE:
			out << "DB " << ((vars[i].value == "") ? "?" : vars[i].value);
			break;
		case ARRAY:
			out << "DD " << vars[i].value;
			break;
		case STRING:
			out << "DB '" << vars[i].value << "'";
			break;
		}
		out << std::endl;
	}
	out << "data_segment ENDS\n\n";
	// ���������� ����
	out << "code_segment SEGMENT\n";
	out << "ASSUME ss:stack_segment, ds:data_segment, cs:code_segment\n";
	out << "begin:\n";
	out << "\tMOV ax, data_segment\n\tMOV ds, ax\n\n";

	OperationBlock *start = oelements.at(0);
	compile_branch(start, out);

	out << "\nEXIT:\n\tMOV ah, 4Ch\n\tINT 21h\n\n";

	out << "code_segment ENDS\n";
	out << "END begin";

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