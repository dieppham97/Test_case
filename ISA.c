#include "ISA.h"
#include <stdio.h>
#include <stdint.h>

D2SSA decodeD2SSA(uint32_t instr)
{
  D2SSA dcode;

  // Extract fields from the instruction
  dcode.p = (instr & 0x1);
  dcode.s = (instr >> 1) & 0x1;
  dcode.unit = (instr >> 2) & 0x7;
  dcode.opcode = (instr >> 5) & 0x1FF;
  dcode.src1 = (instr >> 14) & 0x3F;
  dcode.src2 = (instr >> 20) & 0x3F;
  dcode.dst = (instr >> 26) & 0x3F;

  // Print binary representation for debugging
  printf("Instruction in binary: ");
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (instr >> i) & 0x1);
  }
  printf("\n");

  return dcode;
}

D2SS decodeD2SS(uint32_t instr)
{
  D2SS dcode;

  // Extract fields from the instruction
  dcode.p = (instr & 0x1);
  dcode.s = (instr >> 1) & 0x1;
  dcode.opcode = (instr >> 2) & 0x3FF;
  dcode.src1 = (instr >> 12) & 0x1F;
  dcode.src2 = (instr >> 17) & 0x1F;
  dcode.v = (instr >> 22) & 0x1;
  dcode.dst = (instr >> 23) & 0x3F;

  // Print binary representation for debugging
  printf("Instruction in binary: ");
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (instr >> i) & 0x1);
  }
  printf("\n");

  return dcode;
}