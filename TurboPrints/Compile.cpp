#include "Compile.h"

std::vector<Var> vars;

void compile()
{
	std::cout << "Start compile" << std::endl;

    std::ofstream out;          // ����� ��� ������
    out.open("./out.asm"); // �������� ���� ��� ������
    if (out.is_open())
    {
        out << ";CREATED BY TURBOPRINTS\n";
    }
    std::string error;

    // ����������
 

    if(error != "")
        std::cout << "ERROR " + error << std::endl;
    else
        std::cout << "COMPILE SUCCESS\n";

    out.close();
}