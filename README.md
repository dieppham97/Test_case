# Instruction Set Architecture Simulator

This project simulates a simple instruction set architecture (ISA) with a focus on decoding and executing instructions.

## Files

- `ISA.h`: Header file defining the instruction formats and decode functions
- `ISA.c`: Implementation of the decode functions
- `main.c`: Main program for interactive instruction simulation
- `test_instruction.c`: Test program demonstrating instruction creation and decoding

## Instruction Formats

The simulator supports two instruction formats:

### 1. D2SSA Format

The D2SSA format is defined by the `D2SSA` structure in `ISA.h`:

```c
typedef struct Mem
{
  uint32_t p : 1;      // 1 bit
  uint32_t s : 1;      // 1 bit
  uint32_t unit : 3;   // 3 bits
  uint32_t opcode : 9; // 9 bits
  uint32_t src1 : 6;   // 6 bits
  uint32_t src2 : 6;   // 6 bits
  uint32_t dst : 6;    // 6 bits
} D2SSA;
```

### 2. D2SS Format

The D2SS format is defined by the `D2SS` structure in `ISA.h`:

```c
typedef struct ISA_D2SS
{
  uint32_t p : 1;      // 1 bit
  uint32_t s : 1;      // 1 bit
  uint32_t opcode : 10; // 10 bits
  uint32_t src1 : 5;   // 5 bits
  uint32_t src2 : 5;   // 5 bits
  uint32_t v : 1;      // 1 bit
  uint32_t dst : 6;    // 6 bits
} D2SS;
```

Total instruction width for both formats: 32 bits

## Building and Running

### Compile the main program:

```bash
gcc -o simulator main.c ISA.c
```

### Run the simulator:

```bash
./simulator
```

### Compile and run the test program:

```bash
gcc -o test_instruction test_instruction.c ISA.c
./test_instruction
```

## Usage

### Interactive Mode (main.c)

When you run the simulator, it will prompt you to:

1. Select the input format (hexadecimal or binary)
2. Enter an instruction in the selected format

The program will then automatically detect the instruction format based on the opcode, decode the instruction, and execute it.

#### Input Formats

1. **Hexadecimal**: Enter the instruction as a hexadecimal number (e.g., 0x10000000)
2. **Binary**: Enter the instruction as a 32-bit binary string (e.g., 00010000000000000000000000000000)

#### Automatic Format Detection

The simulator automatically detects the instruction format based on the opcode:

- If the opcode matches a D2SSA instruction (0x1000-0x100B), it will use the D2SSA format
- If the opcode matches a D2SS instruction (0x01000 or 0x01011), it will use the D2SS format
- If the format cannot be determined automatically, the user will be prompted to select the format manually

### Test Program (test_instruction.c)

The test program demonstrates how to create various instructions in both formats and decode them. It shows the binary and hexadecimal representation of each instruction and the decoded fields.

## Supported Instructions

### D2SSA Format Instructions

- `ADDAB`: Adds the values in two source registers and stores the result in a destination register.
- `SUBAB`: Subtracts the second source register from the first and stores the result in a destination register.
- `MULAB`: Multiplies the values in two source registers and stores the result in a destination register.
- `DIVAB`: Divides the first source register by the second and stores the result in a destination register.
- `ANDAB`: Performs a bitwise AND operation on two source registers and stores the result in a destination register.
- `ORAB`: Performs a bitwise OR operation on two source registers and stores the result in a destination register.
- `XORAB`: Performs a bitwise XOR operation on two source registers and stores the result in a destination register.
- `NOTAB`: Performs a bitwise NOT operation on a source register and stores the result in a destination register.
- `SHLAB`: Shifts the first source register left by the amount specified in the second source register and stores the result in a destination register.
- `SHRAB`: Shifts the first source register right by the amount specified in the second source register and stores the result in a destination register.
- `MOVAB`: Copies the value from the first source register to the destination register.
- `CMPAB`: Compares the values in two source registers and stores the result in a destination register (1 if first > second, -1 if first < second, 0 if equal).

### D2SS Format Instructions

- `LDB`: Loads a value from an A register to a D register.
- `LDD`: Loads a value from a D register to an A register.

## Example

### D2SSA Format Example

For an ADDAB instruction with:

- Source 1: 5
- Source 2: 3
- Destination: 0

The instruction would be created as follows:

```c
uint32_t instruction = createADDABInstruction(5, 3, 0);
```

When decoded, it would show:

- Opcode: 0x1000 (ADDAB)
- Source 1: 5
- Source 2: 3
- Destination: 0

### D2SS Format Example

For an LDB instruction with:

- Source 1: 5
- Destination: 0

The instruction would be created as follows:

```c
uint32_t instruction = createLDBInstruction(5, 0);
```

When decoded, it would show:

- Opcode: 0x01000 (LDB)
- Source 1: 5
- Source 2: 0
- V: 0
- Destination: 0

## Adding New Instructions

### Adding a New D2SSA Instruction

1. Define a new opcode in `ISA.h`:

   ```c
   #define OPCODE_NEWINSTR 0x100C
   ```

2. Add a case for the new instruction in the `executeD2SSA` function in `main.c`:

   ```c
   case OPCODE_NEWINSTR: // NEWINSTR instruction
       // Implementation
       break;
   ```

3. Create a helper function to create the new instruction in `test_instruction.c`:

   ```c
   uint32_t createNEWINSTRInstruction(uint8_t src1, uint8_t src2, uint8_t dst)
   {
       return createD2SSAInstruction(OPCODE_NEWINSTR, src1, src2, dst);
   }
   ```

4. Update the `determineInstructionFormat` function in `main.c` to recognize the new opcode:
   ```c
   if ((opcode_d2ssa >= 0x1000 && opcode_d2ssa <= 0x100C) ||
       (opcode_d2ssa >= 0x1000 && opcode_d2ssa <= 0x100C)) {
       return 1; // D2SSA format
   }
   ```

### Adding a New D2SS Instruction

1. Define a new opcode in `ISA.h`:

   ```c
   #define OPCODE_NEWINSTR 0x01012
   ```

2. Add a case for the new instruction in the `executeD2SS` function in `main.c`:

   ```c
   case OPCODE_NEWINSTR: // NEWINSTR instruction
       // Implementation
       break;
   ```

3. Create a helper function to create the new instruction in `test_instruction.c`:

   ```c
   uint32_t createNEWINSTRInstruction(uint8_t src1, uint8_t dst)
   {
       return createD2SSInstruction(OPCODE_NEWINSTR, src1, 0, dst);
   }
   ```

4. Update the `determineInstructionFormat` function in `main.c` to recognize the new opcode:
   ```c
   if (opcode_d2ss == 0x01000 || opcode_d2ss == 0x01011 || opcode_d2ss == 0x01012) {
       return 2; // D2SS format
   }
   ```
