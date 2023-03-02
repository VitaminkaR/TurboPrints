#include "OperationBlockNewLine.h"

void OperationBlockNewLine::CompileBlock(std::ofstream& out)
{
	out << "\n\tCALL newline_func\n";
}