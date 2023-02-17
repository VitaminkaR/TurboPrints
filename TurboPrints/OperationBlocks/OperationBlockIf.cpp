#include "OperationBlockIf.h"

extern int labels_count;

void OperationBlockIf::CompileBlock(std::ofstream& out)
{
	out << "\tMOV BX, " << FirstOperand->Text << "\n\tCMP BX, " << SecondOperand->Text << std::endl;

	// определ€ем есть ли ложна€ ветка
	bool false_branch = true;
	if (BaseOutputConnector->OtherConnectors.at(0)->OtherConnectors.size() == 2)
		false_branch = false;

	std::string operation;

	if (OperationOperand->Text == "=")
		operation = "je";
	else if (OperationOperand->Text == "!=")
		operation = "jne";
	else if (OperationOperand->Text == ">")
		operation = "jb";
	else if (OperationOperand->Text == "<")
		operation = "jl";
	else if (OperationOperand->Text == ">=")
		operation = "jbe";
	else if (OperationOperand->Text == "<=")
		operation = "jle";

	if (false_branch)
	{
		out << "\t" << operation << " L_" << labels_count << "\n\tjmp L_" << labels_count + 1 << "\n\nL_" << labels_count << ":\n";
		// компилируем истиную ветку
		CompileIfBranch(out, TrueConnector);
		out << "\tjmp L_" << labels_count + 2 << "\n";
		// компилируем ложную ветку
		out << "\nL_" << labels_count + 1 << ":\n";
		OperationBlock* shared = CompileIfBranch(out, BaseOutputConnector);
		out << "\nL_" << labels_count + 2 << ":\n";
		// после компил€ции в указатель объекта стандартного выхода блока, помещаем объект с тем самым двойным подключением
		BaseOutputConnector->OtherConnectors.at(0)->ParentObject = shared;
		labels_count += 3;
	}
	else
	{
		out << "\tje L_" << labels_count << "\n\tjmp L_" << labels_count + 1 << "\n\nL_" << labels_count << ":\n";
		// компилируем истиную ветку
		CompileIfBranch(out, TrueConnector);
		out << "\nL_" << labels_count + 1 << ":\n";
		labels_count += 2;
	}
}

void OperationBlockIf::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	SecondOperand->Position = { Position.x - 80 + Size.x - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	OperationOperand->Position = { Position.x - 40 + Size.x / 2 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
	OperationOperand->Handler(e);
	TrueConnector->Handler(e, { Position.x + Size.x - 24 - CamPos->x, Position.y + Size.y - 8 - CamPos->y });
}

void OperationBlockIf::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
	OperationOperand->Draw();
	TrueConnector->Draw();
}

OperationBlock* OperationBlockIf::CompileIfBranch(std::ofstream& out, Connector* connector)
{
	OperationBlock* current_block = (OperationBlock*)connector->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		current_block->CompileBlock(out);
		current_connector = current_block->BaseOutputConnector;
		if (current_connector->OtherConnectors.size() == 0)
			break;
		if (current_connector->OtherConnectors.at(0)->OtherConnectors.size() == 2)
			return (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}