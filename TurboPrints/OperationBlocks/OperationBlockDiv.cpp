#include "OperationBlockDiv.h"

void OperationBlockDiv::CompileBlock(std::ofstream& out)
{
	out << "\tMOV AX, " << InputsOperands->at(0)->Text << std::endl;
	out << "\tMOV BX, " << InputsOperands->at(1)->Text << std::endl;
	out << "\tIDIV BX" << std::endl;
	out << "\tMOV " << InputsOperands->at(0)->Text << ", AX\n";
}