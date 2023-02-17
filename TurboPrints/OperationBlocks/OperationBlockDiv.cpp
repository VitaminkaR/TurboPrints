#include "OperationBlockDiv.h"

void OperationBlockDiv::CompileBlock(std::ofstream& out)
{
	out << "\tMOV AX, " << FirstOperand->Text << std::endl;
	out << "\tMOV BX, " << SecondOperand->Text << std::endl;
	out << "\tIDIV BX" << std::endl;
	out << "\tMOV " << FirstOperand->Text << ", AX\n";
}

void OperationBlockDiv::Handler(SDL_Event& e)
{
	FirstOperand->Position = { Position.x + 16 - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	SecondOperand->Position = { Position.x - 80 + Size.x - CamPos->x, Position.y + Size.y - 64 - CamPos->y };
	FirstOperand->Handler(e);
	SecondOperand->Handler(e);
}

void OperationBlockDiv::Draw()
{
	FirstOperand->Draw();
	SecondOperand->Draw();
}