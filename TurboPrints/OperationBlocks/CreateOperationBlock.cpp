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