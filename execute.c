#include "execute.h"

int determineInstructionFormat(uint32_t instruction)
{
  uint8_t p_bit = instruction & 0x1;

  // Trích xuất opcode từ instruction
  uint16_t opcode = (instruction >> 5) & 0x1F;

  switch (opcode)
  {
  case OPCODE_LDB:
    /* code */
    break;

  default:
    break;
  }
}

void execute(uint32_t instruction)
{
}