# README.yaml

name: "RISC-V Assembly to Machine Code Converter"
description: "A C++ project that converts RISC-V assembly code into machine code. It implements multiple classes to handle different instruction formats and outputs the machine code in a human-readable format."

structure:
  files:
    - name: "main.cpp"
      description: "The main entry point of the program. It reads the assembly instructions from a file and writes the corresponding machine code to an output file."
    - name: "OperationTypes.h"
      description: "Header file containing mappings for different instruction types like R, I, S, SB, U, UJ. It also contains the mappings for funct3, funct7, and opcode."
    - name: "Opcode.h"
      description: "Header file defining the opcodes for different RISC-V operations."

  classes:
    - name: "ASSEMBLER"
      description: "Class responsible for converting parts of the assembly instruction into binary format and extracting different components like operation type, registers, immediate values, etc."
      methods:
        - name: "decimal_To_Binary"
          description: "Converts a decimal value to its binary representation."
        - name: "binary_extend"
          description: "Extends a binary string to a specified length by padding it with leading zeros."
        - name: "get_Operation"
          description: "Extracts the operation mnemonic (e.g., add, sub) from an assembly instruction."
        - name: "get_type"
          description: "Returns the type of the operation (R, I, S, SB, U, UJ)."
        - name: "get_register"
          description: "Extracts the register numbers from an assembly instruction."
        - name: "get_Opcode"
          description: "Returns the opcode for a given operation."
        - name: "get_func3"
          description: "Returns the funct3 value for a given operation."
        - name: "get_funct7"
          description: "Returns the funct7 value for a given operation."
        - name: "get_immediate_addi"
          description: "Extracts the immediate value from an assembly instruction, specifically for 'addi' and similar instructions."

    - name: "ASSEMBELY_TO_MACHINE"
      description: "Class responsible for generating the final machine code and printing it in a human-readable format. Handles different instruction types such as R, I, S, SB, U, UJ."
      methods:
        - name: "print_R_type"
          description: "Prints the R-type instruction in a human-readable format with fields like funct7, rs2, rs1, funct3, rd, and opcode."
        - name: "print_I_type"
          description: "Prints the I-type instruction in a human-readable format with fields like imm[11:0], rs1, funct3, rd, and opcode."
        - name: "print_S_type"
          description: "Prints the S-type instruction in a human-readable format with fields like imm[11:5], rs2, rs1, funct3, imm[4:0], and opcode."
        - name: "print_SB_type"
          description: "Prints the SB-type instruction in a human-readable format with fields like imm[12], imm[10:5], rs2, rs1, funct3, imm[4:1], imm[11], and opcode."
        - name: "print_U_type"
          description: "Prints the U-type instruction in a human-readable format with fields like imm[31:12], rd, and opcode."
        - name: "print_UJ_type"
          description: "Prints the UJ-type instruction in a human-readable format with fields like imm[20], imm[10:1], imm[11], imm[19:12], rd, and opcode."
        - name: "get_Machine_Code"
          description: "Determines the type of the instruction and generates the corresponding machine code, then prints it in a human-readable format."

  usage:
    - name: "read_assembly_write_machine"
      description: "Reads the assembly code from a file, converts it to machine code using ASSEMBELY_TO_MACHINE, and writes the machine code to an output file."

  execution:
    steps:
      - "Ensure the assembly instructions are written in 'assembly.txt'."
      - "Compile the program using a C++ compiler."
      - "Run the program; it will generate a 'machine.txt' file with the corresponding machine code."

