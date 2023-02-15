#include "OperationBlockAdd.h"

void OperationBlockAdd::CompileBlock(std::ofstream& out)
{
	out << "\tADD " << FirstOperand->Text << ", " << SecondOperand->Text << std::endl;
}

void OperationBlockAdd::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	SecondOperand->Position = { Position.x - 80 + Size.x - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
}

void OperationBlockAdd::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
}