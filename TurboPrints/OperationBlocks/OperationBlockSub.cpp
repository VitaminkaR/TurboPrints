#include "OperationBlockSub.h"

void OperationBlockSub::CompileBlock(std::ofstream& out)
{
	out << "\tSUB " << FirstOperand->Text << ", " << SecondOperand->Text << std::endl; 
}

void OperationBlockSub::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16, Position.y + Size.y - 64 };
	SecondOperand->Position = { Position.x - 80 + Size.x, Position.y + Size.y - 64 };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
}

void OperationBlockSub::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
}