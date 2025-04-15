#ifndef ISA_H
#define ISA_H

#include <stdint.h>

// Instruction Opcodes for D2SSA format
#define OPCODE_ADDAB 0x1000
#define OPCODE_SUBAB 0x1001
#define OPCODE_MULAB 0x1002
#define OPCODE_DIVAB 0x1003
#define OPCODE_ANDAB 0x1004
#define OPCODE_ORAB 0x1005
#define OPCODE_XORAB 0x1006
#define OPCODE_NOTAB 0x1007
#define OPCODE_SHLAB 0x1008
#define OPCODE_SHRAB 0x1009
#define OPCODE_MOVAB 0x100A
#define OPCODE_CMPAB 0x100B

// Instruction Opcodes for D2SS format
#define OPCODE_LDB 0x01000
#define OPCODE_LDD 0x01011
// Thêm các opcode mới cho D2SS ở đây

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