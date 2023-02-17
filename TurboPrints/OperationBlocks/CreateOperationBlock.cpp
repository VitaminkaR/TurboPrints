#include "CreateOperationBlock.h"

extern Vector2 camera_position;

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
	case 5:
		b = new OperationBlockIf();
		break;
	case 6:
		b = new OperationBlockFor();
		break;
	}
	b->IsMove = true;
	b->MoveOffset = { b->Size.x / 2 - camera_position.x, b->Size.y / 2 - camera_position.y };
}

void compile_branch(OperationBlock* block, std::ofstream& out)
{
	OperationBlock* current_block = (OperationBlock*)block->BaseOutputConnector->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		if (current_block == 0)
			break;
		current_block->CompileBlock(out);
		current_connector = current_block->BaseOutputConnector;
		if (current_connector->OtherConnectors.size() == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}