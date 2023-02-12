#include "CreateOperationBlock.h"

void create_opeartion_block(int id)
{
	OperationBlock* b = 0;
	switch (id)
	{
	case 0:
		b = new OperationBlockAdd();
		break;
	}
	b->IsMove = true;
}

void compile_branch(OperationBlock* block, std::ofstream &out)
{
	OperationBlock* current_block = (OperationBlock*)block->BaseOutputConnector->OtherConnector->ParentObject;
	Connector* current_connector;
	while (true)
	{
		current_block->CompileBlock(out);
		current_connector = current_block->BaseOutputConnector;
		if (current_connector->OtherConnector == 0)
			break;
		current_block = (OperationBlock*)current_connector->OtherConnector->ParentObject;
	}
}