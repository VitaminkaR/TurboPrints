#include "OperationBlockAdd.h"

void OperationBlockAdd::CompileBlock(std::ofstream& out)
{
	out << "ADD " << FirstOperand->Text << ", " << SecondOperand->Text << std::endl; 
}

void OperationBlockAdd::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16, Position.y + Size.y - 64 };
	SecondOperand->Position = { Position.x - 80 + Size.x, Position.y + Size.y - 64 };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
}

void OperationBlockAdd::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
}