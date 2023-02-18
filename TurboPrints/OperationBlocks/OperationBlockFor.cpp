#include "OperationBlockFor.h"

extern int labels_count;

void OperationBlockFor::CompileBlock(std::ofstream& out)
{
	out << "L_" << labels_count << ":\n";

	OperationBlock* current_block = (OperationBlock*)Connectors->at(2)->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		current_block->CompileBlock(out);
		current_connector = current_block->Connectors->at(1);
		if (current_connector->OtherConnectors.size() == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}

	std::string iters = InputsOperands->at(1)->Text;
	// генерирует бесконечный цикл
	if (iters == "")
	{
		out << "JMP L_" << labels_count << ":\n\n";
		// для оператора break
		out << "L_" << labels_count + 1 << ":\n";
	}
	// генерирует условный цикл (дойти до)
	else
	{
		out << "\tINC " << InputsOperands->at(1)->Text << "\n";
		out << "\tMOV BX, " << InputsOperands->at(0)->Text << "\n";
		out << "\tCMP BX, " << iters << "\n";
		out << "\tJE L_" << labels_count + 1 << "\n";
		out << "\tJMP L_" << labels_count << "\n\n";
		out << "L_" << labels_count + 1 << ":\n";
	}
	labels_count += 2;
}