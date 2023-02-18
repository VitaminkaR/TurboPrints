#include "OperationBlockIf.h"

extern int labels_count;

void OperationBlockIf::CompileBlock(std::ofstream& out)
{
	out << "\tMOV BX, " << InputsOperands->at(0)->Text << "\n\tCMP BX, " << InputsOperands->at(1)->Text << std::endl;

	// определ€ем есть ли ложна€ ветка
	bool false_branch = true;
	if (Connectors->at(1)->OtherConnectors.at(0)->OtherConnectors.size() == 2)
		false_branch = false;

	std::string operation;
	std::string text = InputsOperands->at(2)->Text;
	if (text == "=")
		operation = "je";
	else if (text == "!=")
		operation = "jne";
	else if (text == ">")
		operation = "jb";
	else if (text == "<")
		operation = "jl";
	else if (text == ">=")
		operation = "jbe";
	else if (text == "<=")
		operation = "jle";

	if (false_branch)
	{
		out << "\t" << operation << " L_" << labels_count << "\n\tjmp L_" << labels_count + 1 << "\n\nL_" << labels_count << ":\n";
		// компилируем истиную ветку
		CompileIfBranch(out, Connectors->at(2));
		out << "\tjmp L_" << labels_count + 2 << "\n";
		// компилируем ложную ветку
		out << "\nL_" << labels_count + 1 << ":\n";
		OperationBlock* shared = CompileIfBranch(out, Connectors->at(1));
		out << "\nL_" << labels_count + 2 << ":\n";
		// после компил€ции в указатель объекта стандартного выхода блока, помещаем объект с тем самым двойным подключением
		Connectors->at(1)->OtherConnectors.at(0)->ParentObject = shared;
		labels_count += 3;
	}
	else
	{
		out << "\tje L_" << labels_count << "\n\tjmp L_" << labels_count + 1 << "\n\nL_" << labels_count << ":\n";
		// компилируем истиную ветку
		CompileIfBranch(out, Connectors->at(2));
		out << "\nL_" << labels_count + 1 << ":\n";
		labels_count += 2;
	}
}

OperationBlock* OperationBlockIf::CompileIfBranch(std::ofstream& out, Connector* connector)
{
	OperationBlock* current_block = (OperationBlock*)connector->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		current_block->CompileBlock(out);
		current_connector = current_block->Connectors->at(1);
		if (current_connector->OtherConnectors.size() == 0)
			break;
		if (current_connector->OtherConnectors.at(0)->OtherConnectors.size() == 2)
			return (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}