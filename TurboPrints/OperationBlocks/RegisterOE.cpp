#include "RegisterOE.h"

OperationElement* create_operation_element(int x, int y, int type)
{
	switch (type)
	{
	case 0:
		AddOE * el = new AddOE(0, 0);
		el->IsMove = true;
		return el;
		break;
	}
	return 0;
}