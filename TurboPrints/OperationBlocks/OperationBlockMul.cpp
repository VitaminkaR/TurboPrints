#include "OperationBlockMul.h"

void OperationBlockMul::CompileBlock(std::ofstream& out)
{
	out << "\tMOV AX, " << FirstOperand->Text << std::endl;
	out << "\tIMUL " << SecondOperand->Text << std::endl;
	out << "\tMOV " << FirstOperand->Text << ", AX\n";
}

void OperationBlockMul::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	SecondOperand->Position = { Position.x - 80 + Size.x - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
}

void OperationBlockMul::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
}