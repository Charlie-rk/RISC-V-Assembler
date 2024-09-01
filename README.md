

# "RISC-V Assembly to Machine Code Converter"
 "A C++ project that converts RISC-V assembly code into machine code. It implements multiple classes to handle different instruction formats and outputs the machine code in a human-readable format."
 ## Project structure
 
```sh
.
├── main.cpp
│   ├── ASSEMBLER
│   │   ├── decimal_To_Binary(int reg)
│   │   ├── binary_extend(string &bin, int to_value)
│   │   ├── get_Operation(string &line)
│   │   ├── get_type(string &operation)
│   │   ├── get_register(string &line)
│   │   ├── get_Opcode(string &operation)
│   │   ├── get_func3(string &operation)
│   │   ├── get_funct7(string &operation)
│   │   └── get_immediate_addi(string &line, bool addi)
│   ├── ASSEMBELY_TO_MACHINE
│   │   ├── print_R_type(string &machine_Code)
│   │   ├── print_SB_type(const string &machine_Code)
│   │   ├── print_I_type(const string &machine_Code)
│   │   ├── print_S_type(const string &machine_Code)
│   │   ├── print_U_type(const string &machine_Code)
│   │   ├── print_UJ_type(const string &machine_Code)
│   │   └── get_Machine_Code(string &line)
│   ├── R_type_addresing_Instr(string &line, string &operation)
│   ├── I_type_addresing_Instr(string &line, string &operation)
│   ├── S_type_addresing_Instr(string &line, string &operation)
│   ├── SB_type_addresing_Instr(string &line, string &operation)
│   ├── UJ_type_addresing_Instr(string &line, string &operation)
│   ├── U_type_addresing_Instr(string &line, string &operation)
│   └── read_assembly_write_machine(const string &filename, ofstream &outFile)
├── OperationTypes.h
│   └── (Content not detailed here)
├── Opcode.h
│   └── (Content not detailed here)
└── assembly.txt
    └── (Assembly code to be converted)

```
## References
![image](https://github.com/user-attachments/assets/4b2e1718-8c3b-4938-92f4-4beb0f07cff4)
## 
![image](https://github.com/user-attachments/assets/29b2b447-066d-400e-8a18-8fb7c75715e7)
##
![image](https://github.com/user-attachments/assets/c0111ebc-d057-4924-b1fc-4a6ba4dc573a)



