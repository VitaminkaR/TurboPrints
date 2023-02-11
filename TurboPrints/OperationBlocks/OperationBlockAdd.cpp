#include "OperationBlockAdd.h"

void OperationBlockAdd::CompileBlock(std::ofstream& out)
{
	out << "ETO TIPA ADD" << std::endl;
}

void OperationBlockAdd::Handler(SDL_Event& e)
{

}

void OperationBlockAdd::Draw()
{

}