#include "RegisterOE.h"

ElementType element_types[OETYPES_COUNT] =
{
	{"ADD", 0},
	{"SUB", 0},
};

OperationElement* create_operation_element(int type)
{
	switch (type)
	{
	case 0:
		AddOE * el = new AddOE(0, 0);
		el->IsMove = true;
		el->MoveOffset = {128, 64};
		return el;
		break;
	}
	return 0;
}