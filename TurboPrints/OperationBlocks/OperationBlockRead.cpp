#include "OperationBlockRead.h"

void OperationBlockRead::CompileBlock(std::ofstream& out)
{
	out << "\tPUSH DX\n"
		<< "\tLEA DX, " << InputsOperands->at(0)->Text
		<< "\n\tCALL read_func\n"
		<< "\tPOP DX\n";
}