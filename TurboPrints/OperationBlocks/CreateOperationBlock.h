#pragma once

#include "OperationBlock.h"
#include "OperationBlockAdd.h"
#include "OperationBlockBegin.h"
#include "OperationBlockSub.h"
#include "OperationBlockIf.h"

void create_opeartion_block(int id);
void compile_branch(OperationBlock* block, std::ofstream &out);