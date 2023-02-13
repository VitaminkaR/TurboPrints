#include "OperationBlockIf.h"

extern int labels_count;

void OperationBlockIf::CompileBlock(std::ofstream& out)
{
	out << "\tMOV BX, " << FirstOperand->Text << "\n\tCMP BX, " << SecondOperand->Text << std::endl; 
	if (OperationOperand->Text == "=")
	{
		out << "\tje L_" << labels_count << "\n\tjmp L_" << labels_count + 1 << "\n\nL_" << labels_count << ":\n";
		// компилируем истиную ветку
		CompileIfBranch(out, TrueConnector);
		out << "\tjmp L_" << labels_count + 2 << "\n";
		// компилируем ложную ветку
		out << "\nL_" << labels_count + 1 << ":\n";
		OperationBlock *shared = CompileIfBranch(out, BaseOutputConnector);
		out << "\nL_" << labels_count + 2 << ":\n";
		// после компил€ции в указатель объекта стандартного выхода блока, помещаем объект с тем самым двойным подключением
		BaseOutputConnector->OtherConnectors.at(0)->ParentObject = shared;
		labels_count += 3;
	}
}

void OperationBlockIf::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16, Position.y + Size.y - 64 };
	SecondOperand->Position = { Position.x - 80 + Size.x, Position.y + Size.y - 64 };
	OperationOperand->Position = { Position.x - 40 + Size.x / 2, Position.y + Size.y - 64 };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
	OperationOperand->Handler(e);
	TrueConnector->Handler(e, { Position.x + Size.x - 24, Position.y + Size.y - 8 });
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
		if(current_connector->OtherConnectors.at(0)->OtherConnectors.size() == 2)
			return (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}