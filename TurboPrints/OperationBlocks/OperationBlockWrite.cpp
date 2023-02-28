#include "OperationBlockWrite.h"

void OperationBlockWrite::CompileBlock(std::ofstream& out)
{
	out << "\tPUSH DX\n"
		<< "\tLEA DX, " << InputsOperands->at(0)->Text
		<< "\n\tCALL write_func\n"
		<< "\tPOP DX\n";
}