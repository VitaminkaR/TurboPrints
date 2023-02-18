#include "OperationBlockMul.h"

void OperationBlockMul::CompileBlock(std::ofstream& out)
{
	out << "\tMOV AX, " << InputsOperands->at(0)->Text << std::endl;
	out << "\tMOV BX, " << InputsOperands->at(1)->Text << std::endl;
	out << "\tIMUL BX" << std::endl;
	out << "\tMOV " << InputsOperands->at(0)->Text << ", AX\n";
}