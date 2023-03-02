#include "CreateOperationBlock.h"

extern Vector2 camera_position;

std::string operation_types[TYPES_COUNT]
{
	"ADD",
	"SUB",
	"MUL",
	"DIV",
	"MOD",
	"IF",
	"FOR",
	"WRITE",
	"READ",
	"NEW LINE"
};

void create_opeartion_block(int id)
{
	OperationBlock* b = 0;
	switch (id)
	{
	case 0:
		b = new OperationBlockAdd();
		break;
	case 1:
		b = new OperationBlockSub();
		break;
	case 2:
		b = new OperationBlockMul();
		break;
	case 3:
		b = new OperationBlockDiv();
		break;
	case 4:
		b = new OperationBlockMod();
		break;
	case 5:
		b = new OperationBlockIf();
		break;
	case 6:
		b = new OperationBlockFor();
		break;
	case 7:
		b = new OperationBlockWrite();
		break;
	case 8:
		b = new OperationBlockRead();
		break;
	case 9:
		b = new OperationBlockNewLine();
		break;
	}
	b->IsMove = true;
	b->MoveOffset = { b->Size.x / 2 - camera_position.x, b->Size.y / 2 - camera_position.y };
}

void compile_branch(OperationBlock* block, std::ofstream& out)
{
	OperationBlock* current_block = (OperationBlock*)block->Connectors->at(1)->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		if (current_block == 0)
			break;
		current_block->CompileBlock(out);
		current_connector = current_block->Connectors->at(1);
		if (current_connector->OtherConnectors.size() == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}