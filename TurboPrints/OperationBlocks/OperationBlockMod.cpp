#include "OperationBlockMod.h"

void OperationBlockMod::CompileBlock(std::ofstream& out)
{
	out << "\tMOV AX, " << InputsOperands->at(0)->Text << std::endl;
	out << "\tMOV BX, " << InputsOperands->at(1)->Text << std::endl;
	out << "\IDIV BX" << std::endl;
	out << "\tMOV " << InputsOperands->at(0)->Text << ", DX\n";
}