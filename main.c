#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ISA.h"

uint8_t A[16];
uint8_t D[16];

void executeD2SSA(D2SSA decoded_instr)
{
	switch (decoded_instr.opcode)
	{
	case OPCODE_ADDAB: // ADDAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] + A[decoded_instr.src2];
		printf("Executing ADDAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_SUBAB: // SUBAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] - A[decoded_instr.src2];
		printf("Executing SUBAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_MULAB: // MULAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] * A[decoded_instr.src2];
		printf("Executing MULAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_DIVAB: // DIVAB instruction
		if (A[decoded_instr.src2] != 0)
		{
			A[decoded_instr.dst] = A[decoded_instr.src1] / A[decoded_instr.src2];
			printf("Executing DIVAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
						 decoded_instr.src1, A[decoded_instr.src1],
						 decoded_instr.src2, A[decoded_instr.src2],
						 decoded_instr.dst, A[decoded_instr.dst]);
		}
		else
		{
			printf("Error: Division by zero\n");
		}
		break;

	case OPCODE_ANDAB: // ANDAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] & A[decoded_instr.src2];
		printf("Executing ANDAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_ORAB: // ORAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] | A[decoded_instr.src2];
		printf("Executing ORAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_XORAB: // XORAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] ^ A[decoded_instr.src2];
		printf("Executing XORAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_NOTAB: // NOTAB instruction
		A[decoded_instr.dst] = ~A[decoded_instr.src1];
		printf("Executing NOTAB with src1: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_SHLAB: // SHLAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] << A[decoded_instr.src2];
		printf("Executing SHLAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_SHRAB: // SHRAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1] >> A[decoded_instr.src2];
		printf("Executing SHRAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_MOVAB: // MOVAB instruction
		A[decoded_instr.dst] = A[decoded_instr.src1];
		printf("Executing MOVAB with src1: A%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	case OPCODE_CMPAB: // CMPAB instruction
		if (A[decoded_instr.src1] > A[decoded_instr.src2])
		{
			A[decoded_instr.dst] = 1;
		}
		else if (A[decoded_instr.src1] < A[decoded_instr.src2])
		{
			A[decoded_instr.dst] = -1;
		}
		else
		{
			A[decoded_instr.dst] = 0;
		}
		printf("Executing CMPAB with src1: A%d=%u, src2: A%d=%u, dst: A%d=%d\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.src2, A[decoded_instr.src2],
					 decoded_instr.dst, (int8_t)A[decoded_instr.dst]);
		break;

	default:
		printf("Unsupported opcode: 0x%X\n", decoded_instr.opcode);
	}
}

void executeD2SS(D2SS decoded_instr)
{
	switch (decoded_instr.opcode)
	{
	case OPCODE_LDB: // LDB instruction
		D[decoded_instr.dst] = A[decoded_instr.src1];
		printf("Executing LDB with src1: A%d=%u, dst: D%d=%u\n",
					 decoded_instr.src1, A[decoded_instr.src1],
					 decoded_instr.dst, D[decoded_instr.dst]);
		break;

	case OPCODE_LDD: // LDD instruction
		A[decoded_instr.dst] = D[decoded_instr.src1];
		printf("Executing LDD with src1: D%d=%u, dst: A%d=%u\n",
					 decoded_instr.src1, D[decoded_instr.src1],
					 decoded_instr.dst, A[decoded_instr.dst]);
		break;

	default:
		printf("Unsupported opcode: 0x%X\n", decoded_instr.opcode);
	}
}

void printDecodedD2SSAInstruction(D2SSA decoded_instr)
{
	printf("\nDecoded D2SSA Instruction:\n");
	printf("  P: %u\n", decoded_instr.p);
	printf("  S: %u\n", decoded_instr.s);
	printf("  Unit: 0x%X\n", decoded_instr.unit);
	printf("  Opcode: 0x%X\n", decoded_instr.opcode);
	printf("  Source 1: %u\n", decoded_instr.src1);
	printf("  Source 2: %u\n", decoded_instr.src2);
	printf("  Destination: %u\n", decoded_instr.dst);
}

void printDecodedD2SSInstruction(D2SS decoded_instr)
{
	printf("\nDecoded D2SS Instruction:\n");
	printf("  P: %u\n", decoded_instr.p);
	printf("  S: %u\n", decoded_instr.s);
	printf("  Opcode: 0x%X\n", decoded_instr.opcode);
	printf("  Source 1: %u\n", decoded_instr.src1);
	printf("  Source 2: %u\n", decoded_instr.src2);
	printf("  V: %u\n", decoded_instr.v);
	printf("  Destination: %u\n", decoded_instr.dst);
}

// Hàm để xác định định dạng instruction dựa vào opcode
int determineInstructionFormat(uint32_t instruction)
{
	// Trích xuất opcode từ instruction
	uint32_t opcode_d2ssa = (instruction >> 5) & 0x1FF; // 9 bits cho D2SSA
	uint32_t opcode_d2ss = (instruction >> 2) & 0x3FF;	// 10 bits cho D2SS

	// Kiểm tra xem opcode có phải là D2SSA không
	if ((opcode_d2ssa >= 0x1000 && opcode_d2ssa <= 0x100B) ||
			(opcode_d2ssa >= 0x1000 && opcode_d2ssa <= 0x100B))
	{
		return 1; // D2SSA format
	}

	// Kiểm tra xem opcode có phải là D2SS không
	if (opcode_d2ss == 0x01000 || opcode_d2ss == 0x01011)
	{
		return 2; // D2SS format
	}

	// Nếu không xác định được, trả về 0
	return 0;
}

// Hàm để chuyển đổi chuỗi nhị phân thành số nguyên
uint32_t binaryToUint32(const char *binary)
{
	uint32_t result = 0;
	int len = strlen(binary);

	for (int i = 0; i < len; i++)
	{
		if (binary[i] == '1')
		{
			result |= (1 << (len - 1 - i));
		}
	}

	return result;
}

// Hàm để hiển thị thông tin về unit
void printUnitInfo(uint32_t unit)
{
	printf("  Unit: ");
	switch (unit)
	{
	case 0x3: // 011
		printf("D1 function unit\n");
		break;
	case 0x5: // 101
		printf("D2 function unit\n");
		break;
	default:
		printf("Unknown unit (0x%X)\n", unit);
	}
}

// Hàm để chuyển đổi số hex thành chuỗi nhị phân
void hexToBinary(uint32_t hex, char *binary)
{
	for (int i = 0; i < 32; i++)
	{
		binary[i] = ((hex >> (31 - i)) & 0x01) ? '1' : '0';
	}
	binary[32] = '\0';
}

int main()
{
	// Nhập lệnh hex từ bàn phím
	uint32_t hex_instruction;
	printf("Input instruction in hex (e.g., 0x10000000): ");
	scanf("%x", &hex_instruction);

	// Chuyển đổi hex thành binary
	char binary[33];
	hexToBinary(hex_instruction, binary);

	// Xác định định dạng và thực thi instruction
	int format = determineInstructionFormat(hex_instruction);

	if (format == 1)
	{
		D2SSA decoded_instr = decodeD2SSA(hex_instruction);
		printUnitInfo(decoded_instr.unit);
		executeD2SSA(decoded_instr);
	}
	else if (format == 2)
	{
		D2SS decoded_instr = decodeD2SS(hex_instruction);
		executeD2SS(decoded_instr);
	}
	else
	{
		printf("Unknown instruction format\n");
		return 1;
	}

	return 0;
}
