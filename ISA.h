#ifndef ISA_H
#define ISA_H

#include <stdint.h>

#define QUANTITY_INS_MEM 5

// Instruction Opcodes for D2SS format
#define OPCODE_LDB 0x8
#define OPCODE_LDD 0xB

typedef struct Mem
{
  uint32_t p : 1;
  uint32_t s : 1;
  uint32_t unit : 3;
  uint32_t opcode : 9;
  uint32_t src1 : 6;
  uint32_t src2 : 6;
  uint32_t dst : 6;
} D2SSA;

typedef struct ISA_D2SS
{
  uint32_t p : 1;
  uint32_t s : 1;
  uint32_t opcode : 10;
  uint32_t src1 : 5;
  uint32_t src2 : 5;
  uint32_t v : 1;
  uint32_t dst : 6;
} D2SS;

// Hàm giải mã cho cả hai định dạng
D2SSA decodeD2SSA(uint32_t instr);
D2SS decodeD2SS(uint32_t instr);

// Hàm thực thi cho cả hai định dạng
void executeD2SSA(D2SSA decoded_instr);
void executeD2SS(D2SS decoded_instr);

#endif