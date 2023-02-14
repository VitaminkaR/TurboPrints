#include "CreateOperationBlock.h"

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
		b = new OperationBlockIf();
		break;
	}
	b->IsMove = true;
	b->MoveOffset = {b->Size.x / 2, b->Size.y / 2};
}

void compile_branch(OperationBlock* block, std::ofstream &out)
{
	OperationBlock* current_block = (OperationBlock*)block->BaseOutputConnector->OtherConnectors.at(0)->ParentObject;
	Connector* current_connector;
	while (true)
	{
		if(current_block == 0)
			break;
		current_block->CompileBlock(out);
		current_connector = current_block->BaseOutputConnector;
		if (current_connector->OtherConnectors.size() == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnectors.at(0)->ParentObject;
	}
}