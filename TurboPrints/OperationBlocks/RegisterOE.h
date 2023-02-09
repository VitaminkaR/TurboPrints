#pragma once

#include "../OperationElement.h"
#include "AddOE.h"

const int OETYPES_COUNT = 2;

struct ElementType
{
	std::string name;
	int id;
};

// происходит регистрация элементов (при добавлении нового элемента, прописать его здесь)
// цифра элемента, это ай ди кнопки в ControlPanel, поэтому они должны быть строго согласованы
OperationElement* create_operation_element(int type);