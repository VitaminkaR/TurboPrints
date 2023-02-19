#include "OperationBlockAdd.h"

void OperationBlockAdd::CompileBlock(std::ofstream& out)
{
	out << "\tADD " << InputsOperands->at(0)->Text << ", " << InputsOperands->at(1)->Text << std::endl;
}