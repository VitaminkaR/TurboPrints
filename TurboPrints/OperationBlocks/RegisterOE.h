#pragma once

#include "../OperationElement.h"
#include "AddOE.h"

// происходит регистрация элементов (при добавлении нового элемента, прописать его здесь)
// цифра элемента, это ай ди кнопки в ControlPanel, поэтому они должны быть строго согласованы
OperationElement* create_operation_element(int x, int y, int type);