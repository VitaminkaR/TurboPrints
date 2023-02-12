#pragma once

#include "OperationBlock.h"
#include "OperationBlockAdd.h"
#include "OperationBlockBegin.h"

void create_opeartion_block(int id);
void compile_branch(OperationBlock* block, std::ofstream &out);