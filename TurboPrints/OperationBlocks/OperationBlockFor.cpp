#include "OperationBlockFor.h"

extern int labels_count;

void OperationBlockFor::CompileBlock(std::ofstream& out)
{
	out << "L_" << labels_count << ":\n";

	OperationBlock* current_block = (OperationBlock*)CycleConnector->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		current_block->CompileBlock(out);
		current_connector = current_block->BaseOutputConnector;
		if (current_connector->OtherConnectors.size() == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}

	std::string iters = SecondOperand->Text;
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
		out << "\tINC " << FirstOperand->Text << "\n";
		out << "\tMOV BX, " << FirstOperand->Text << "\n";
		out << "\tCMP BX, " << iters << "\n";
		out << "\tJE L_" << labels_count + 1 << "\n";
		out << "\tJMP L_" << labels_count << "\n\n";
		out << "L_" << labels_count + 1 << ":\n";
	}
	labels_count += 2;
}

void OperationBlockFor::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	SecondOperand->Position = { Position.x - 80 + Size.x - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
	CycleConnector->Handler(e, { Position.x + Size.x - 24 - CamPos->x, Position.y + Size.y - 8 - CamPos->y });
}

void OperationBlockFor::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
	CycleConnector->Draw();
}