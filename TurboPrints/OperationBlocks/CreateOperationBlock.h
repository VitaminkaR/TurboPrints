#pragma once

#include "OperationBlock.h"
#include "OperationBlockAdd.h"
#include "OperationBlockBegin.h"
#include "OperationBlockSub.h"
#include "OperationBlockIf.h"
#include "OperationBlockFor.h"
#include "OperationBlockMul.h"
#include "OperationBlockDiv.h"
#include "OperationBlockMod.h"
#include "OperationBlockWrite.h"
#include "OperationBlockRead.h"
#include "OperationBlockNewLine.h"

const int TYPES_COUNT = 10;

void create_opeartion_block(int id);
void compile_branch(OperationBlock* block, std::ofstream &out);