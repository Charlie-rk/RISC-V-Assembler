# README.yaml

name: "<span style='color:blue'>RISC-V Assembly to Machine Code Converter</span>"
description: "<span style='color:blue'>A C++ project that converts RISC-V assembly code into machine code. It implements multiple classes to handle different instruction formats and outputs the machine code in a human-readable format.</span>"

structure:
  files:
    - name: "<span style='color:blue'>main.cpp</span>"
      description: "The main entry point of the program. It reads the assembly instructions from a file and writes the corresponding machine code to an output file."
    - name: "<span style='color:blue'>OperationTypes.h</span>"
      description: "Header file containing mappings for different instruction types like R, I, S, SB, U, UJ. It also contains the mappings for funct3, funct7, and opcode."
    - name: "<span style='color:blue'>Opcode.h</span>"
      description: "Header file defining the opcodes for different RISC-V operations."

  classes:
    - name: "<span style='color:blue'>ASSEMBLER</span>"
      description: "Class responsible for converting parts of the assembly instruction into binary format and extracting different components like operation type, registers, immediate values, etc."
      methods:
        - name: "<span style='color:blue'>decimal_To_Binary</span>"
          description: "Converts a decimal value to its binary representation."
        - name: "<span style='color:blue'>binary_extend</span>"
          description: "Extends a binary string to a specified length by padding it with leading zeros."
        - name: "<span style='color:blue'>get_Operation</span>"
          description: "Extracts the operation mnemonic (e.g., add, sub) from an assembly instruction."
        - name: "<span style='color:blue'>get_type</span>"
          description: "Returns the type of the operation (R, I, S, SB, U, UJ)."
        - name: "<span style='color:blue'>get_register</span>"
          description: "Extracts the register numbers from an assembly instruction."
        - name: "<span style='color:blue'>get_Opcode</span>"
          description: "Returns the opcode for a given operation."
        - name: "<span style='color:blue'>get_func3</span>"
          description: "Returns the funct3 value for a given operation."
        - name: "<span style='color:blue'>get_funct7</span>"
          description: "Returns the funct7 value for a given operation."
        - name: "<span style='color:blue'>get_immediate_addi</span>"
          description: "Extracts the immediate value from an assembly instruction, specifically for 'addi' and similar instructions."

    - name: "<span style='color:blue'>ASSEMBELY_TO_MACHINE</span>"
      description: "Class responsible for generating the final machine code and printing it in a human-readable format. Handles different instruction types such as R, I, S, SB, U, UJ."
      methods:
        - name: "<span style='color:blue'>print_R_type</span>"
          description: "Prints the R-type instruction in a human-readable format with fields like funct7, rs2, rs1, funct3, rd, and opcode."
        - name: "<span style='color:blue'>print_I_type</span>"
          description: "Prints the I-type instruction in a human-readable format with fields like imm[11:0], rs1, funct3, rd, and opcode."
        - name: "<span style='color:blue'>print_S_type</span>"
          description: "Prints the S-type instruction in a human-readable format with fields like imm[11:5], rs2, rs1, funct3, imm[4:0], and opcode."
        - name: "<span style='color:blue'>print_SB_type</span>"
          description: "Prints the SB-type instruction in a human-readable format with fields like imm[12], imm[10:5], rs2, rs1, funct3, imm[4:1], imm[11], and opcode."
        - name: "<span style='color:blue'>print_U_type</span>"
          description: "Prints the U-type instruction in a human-readable format with fields like imm[31:12], rd, and opcode."
        - name: "<span style='color:blue'>print_UJ_type</span>"
          description: "Prints the UJ-type instruction in a human-readable format with fields like imm[20], imm[10:1], imm[11], imm[19:12], rd, and opcode."
        - name: "<span style='color:blue'>get_Machine_Code</span>"
          description: "Determines the type of the instruction and generates the corresponding machine code, then prints it in a human-readable format."

  usage:
    - name: "<span style='color:blue'>read_assembly_write_machine</span>"
      description: "Reads the assembly code from a file, converts it to machine code using ASSEMBELY_TO_MACHINE, and writes the machine code to an output file."

  execution:
    steps:
      - "<span style='color:blue'>Ensure the assembly instructions are written in 'assembly.txt'.</span>"
      - "<span style='color:blue'>Compile the program using a C++ compiler.</span>"
      - "<span style='color:blue'>Run the program; it will generate a 'machine.txt' file with the corresponding machine code.</span>"
