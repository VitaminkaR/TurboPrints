#include "OperationBlockSub.h"

void OperationBlockSub::CompileBlock(std::ofstream& out)
{
	out << "\tSUB " << InputsOperands->at(0)->Text << ", " << InputsOperands->at(1)->Text << std::endl;
}