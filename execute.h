#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ISA.h"

int determineInstructionFormat(uint32_t instruction);

void execute (uint32_t instruction);

#endif