#include "Compile.h"

std::vector<Var> vars;

void compile()
{
	std::cout << "Start compile" << std::endl;

    std::ofstream out;          // поток дл€ записи
    out.open("./out.asm"); // окрываем файл дл€ записи
    if (out.is_open())
    {
        out << ";CREATED BY TURBOPRINTS\n\n";
    }
    std::string error;

    // компил€ци€
    // компил€ци€ data segment
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

    if(error != "")
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
    }
}