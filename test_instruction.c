#include <stdio.h>
#include <stdint.h>
#include "ISA.h"

// Function to print binary representation of a number
void printBinary(uint32_t num)
{
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (num >> i) & 0x1);
  }
  printf("\n");
}

// Function to create a D2SSA instruction with specified opcode and registers
uint32_t createD2SSAInstruction(uint32_t opcode, uint8_t src1, uint8_t src2, uint8_t dst)
{
  uint32_t instruction = 0;

  // Set opcode
  instruction |= (opcode << 5);

  // Set source registers
  instruction |= ((uint32_t)src1 << 14);
  instruction |= ((uint32_t)src2 << 20);

  // Set destination register
  instruction |= ((uint32_t)dst << 26);

  return instruction;
}

// Function to create a D2SS instruction with specified opcode and registers
uint32_t createD2SSInstruction(uint32_t opcode, uint8_t src1, uint8_t src2, uint8_t dst)
{
  uint32_t instruction = 0;

  // Set opcode
  instruction |= (opcode << 2);

  // Set source registers
  instruction |= ((uint32_t)src1 << 12);
  instruction |= ((uint32_t)src2 << 17);

  // Set v bit (default to 0)
  instruction |= (0 << 22);

  // Set destination register
  instruction |= ((uint32_t)dst << 23);

  return instruction;
}

// Function to create an ADDAB instruction
uint32_t createADDABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_ADDAB, src1, src2, dst);
}

// Function to create a SUBAB instruction
uint32_t createSUBABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_SUBAB, src1, src2, dst);
}

// Function to create a MULAB instruction
uint32_t createMULABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_MULAB, src1, src2, dst);
}

// Function to create a DIVAB instruction
uint32_t createDIVABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_DIVAB, src1, src2, dst);
}

// Function to create an ANDAB instruction
uint32_t createANDABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_ANDAB, src1, src2, dst);
}

// Function to create an ORAB instruction
uint32_t createORABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_ORAB, src1, src2, dst);
}

// Function to create an XORAB instruction
uint32_t createXORABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_XORAB, src1, src2, dst);
}

// Function to create a NOTAB instruction
uint32_t createNOTABInstruction(uint8_t src1, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_NOTAB, src1, 0, dst);
}

// Function to create a SHLAB instruction
uint32_t createSHLABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_SHLAB, src1, src2, dst);
}

// Function to create a SHRAB instruction
uint32_t createSHRABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_SHRAB, src1, src2, dst);
}

// Function to create a MOVAB instruction
uint32_t createMOVABInstruction(uint8_t src1, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_MOVAB, src1, 0, dst);
}

// Function to create a CMPAB instruction
uint32_t createCMPABInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
{
  return createD2SSAInstruction(OPCODE_CMPAB, src1, src2, dst);
}

// Function to create an LDB instruction
uint32_t createLDBInstruction(uint8_t src1, uint8_t dst)
{
  return createD2SSInstruction(OPCODE_LDB, src1, 0, dst);
}

// Function to create an LDD instruction
uint32_t createLDDInstruction(uint8_t src1, uint8_t dst)
{
  return createD2SSInstruction(OPCODE_LDD, src1, 0, dst);
}

void testD2SSAInstruction(uint32_t instruction, const char *instructionName)
{
  printf("\nTesting D2SSA %s instruction:\n", instructionName);
  printf("Instruction in hexadecimal: 0x%08X\n", instruction);
  printf("Instruction in binary: ");
  printBinary(instruction);

  // Decode the instruction
  D2SSA decoded = decodeD2SSA(instruction);

  printf("\nDecoded fields:\n");
  printf("  P: %u\n", decoded.p);
  printf("  S: %u\n", decoded.s);
  printf("  Unit: 0x%X\n", decoded.unit);
  printf("  Opcode: 0x%X\n", decoded.opcode);
  printf("  Source 1: %u\n", decoded.src1);
  printf("  Source 2: %u\n", decoded.src2);
  printf("  Destination: %u\n", decoded.dst);

  // Execute the instruction
  executeD2SSA(decoded);
}

void testD2SSInstruction(uint32_t instruction, const char *instructionName)
{
  printf("\nTesting D2SS %s instruction:\n", instructionName);
  printf("Instruction in hexadecimal: 0x%08X\n", instruction);
  printf("Instruction in binary: ");
  printBinary(instruction);

  // Decode the instruction
  D2SS decoded = decodeD2SS(instruction);

  printf("\nDecoded fields:\n");
  printf("  P: %u\n", decoded.p);
  printf("  S: %u\n", decoded.s);
  printf("  Opcode: 0x%X\n", decoded.opcode);
  printf("  Source 1: %u\n", decoded.src1);
  printf("  Source 2: %u\n", decoded.src2);
  printf("  V: %u\n", decoded.v);
  printf("  Destination: %u\n", decoded.dst);

  // Execute the instruction
  executeD2SS(decoded);
}

int main()
{
  printf("Instruction Set Architecture Simulator\n");
  printf("=====================================\n\n");

  // Test D2SSA instructions
  printf("Testing D2SSA Instructions:\n");
  printf("---------------------------\n");

  // Test ADDAB instruction
  uint32_t addabInstruction = createADDABInstruction(5, 3, 0);
  testD2SSAInstruction(addabInstruction, "ADDAB");

  // Test SUBAB instruction
  uint32_t subabInstruction = createSUBABInstruction(5, 3, 1);
  testD2SSAInstruction(subabInstruction, "SUBAB");

  // Test MULAB instruction
  uint32_t mulabInstruction = createMULABInstruction(5, 3, 2);
  testD2SSAInstruction(mulabInstruction, "MULAB");

  // Test DIVAB instruction
  uint32_t divabInstruction = createDIVABInstruction(10, 2, 3);
  testD2SSAInstruction(divabInstruction, "DIVAB");

  // Test ANDAB instruction
  uint32_t andabInstruction = createANDABInstruction(5, 3, 4);
  testD2SSAInstruction(andabInstruction, "ANDAB");

  // Test ORAB instruction
  uint32_t orabInstruction = createORABInstruction(5, 3, 5);
  testD2SSAInstruction(orabInstruction, "ORAB");

  // Test XORAB instruction
  uint32_t xorabInstruction = createXORABInstruction(5, 3, 6);
  testD2SSAInstruction(xorabInstruction, "XORAB");

  // Test NOTAB instruction
  uint32_t notabInstruction = createNOTABInstruction(5, 7);
  testD2SSAInstruction(notabInstruction, "NOTAB");

  // Test SHLAB instruction
  uint32_t shlabInstruction = createSHLABInstruction(5, 2, 8);
  testD2SSAInstruction(shlabInstruction, "SHLAB");

  // Test SHRAB instruction
  uint32_t shrabInstruction = createSHRABInstruction(10, 1, 9);
  testD2SSAInstruction(shrabInstruction, "SHRAB");

  // Test MOVAB instruction
  uint32_t movabInstruction = createMOVABInstruction(5, 10);
  testD2SSAInstruction(movabInstruction, "MOVAB");

  // Test CMPAB instruction
  uint32_t cmpabInstruction = createCMPABInstruction(5, 3, 11);
  testD2SSAInstruction(cmpabInstruction, "CMPAB");

  // Test D2SS instructions
  printf("\nTesting D2SS Instructions:\n");
  printf("---------------------------\n");

  // Test LDB instruction
  uint32_t ldbInstruction = createLDBInstruction(5, 0);
  testD2SSInstruction(ldbInstruction, "LDB");

  // Test LDD instruction
  uint32_t lddInstruction = createLDDInstruction(5, 0);
  testD2SSInstruction(lddInstruction, "LDD");

  return 0;
}