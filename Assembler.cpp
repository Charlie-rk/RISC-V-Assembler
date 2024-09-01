#include <bits/stdc++.h>
#include "OperationTypes.h"
#include "Opcode.h"
using namespace std;
class ASSEMBLER
{
public:
    string decimal_To_Binary(int reg);
    void binary_extend(string &bin, int to_value);
    string get_Operation(string &line);
    string get_type(string &operation);
    vector<int> get_register(string &line);
    string get_Opcode(string &operation);
    string get_func3(string &operation);
    string get_funct7(string &operation);
    int get_immediate_addi(string &line, bool addi);
};

int ASSEMBLER::get_immediate_addi(string &line, bool addi)
{
    string ans = "";
    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[i] == ',')
        {
            break;
        }
        if (addi)
        {
            if (line[i] == '(')
            {
                addi = false;
            }
            continue;
        }

        ans += line[i];
    }
    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

string ASSEMBLER::get_func3(string &operation)
{
    if (funct3.find(operation) != funct3.end())
    {
        return funct3[operation];
    }
    return "UNKNOWN";
}

string ASSEMBLER::get_funct7(string &operation)
{
    if (funct7.find(operation) != funct7.end())
    {
        return funct7[operation];
    }
    return "UNKNOWN";
}
string ASSEMBLER::get_Opcode(string &operation)
{
    if (opcode.find(operation) != opcode.end())
    {
        return opcode[operation];
    }
    return "UNKNOWN";
}

vector<int> ASSEMBLER::get_register(string &line)
{
    vector<int> ans;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == 'x' && i > 0)
        {
            string temp = "";
            for (int j = i + 1; j < line.size(); j++)
            {
                if (line[j] == ',' || line[j] == ')' || line[j] == ';')
                {
                    break;
                }
                temp += line[j];
            }
            int val = stoi(temp);
            ans.push_back(val);
        }
    }
    return ans;
}

string ASSEMBLER::get_type(string &operation)
{
    if (type_map.find(operation) != type_map.end())
    {
        return type_map[operation];
    }
    return "UNKNOWN";
}

string ASSEMBLER::get_Operation(string &line)
{
    string op = "";
    for (auto it : line)
    {
        if (it == ' ')
        {
            break;
        }
        op += it;
    }
    return op;
}
void ASSEMBLER::binary_extend(string &bin, int to_value)
{
    int len = bin.size();
    int req = to_value - len;
    while (req > 0)
    {
        bin = "0" + bin;
        req--;
    }
    // return bin;
}
string ASSEMBLER::decimal_To_Binary(int reg)
{
    string binary = "";
    while (reg != 0)
    {
        int data = reg % 2;
        string val = to_string(data);
        binary += val;
        reg = reg / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

string R_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    ans += as.get_funct7(operation);
    vector<int> reg;
    reg = as.get_register(line);
    int rs2 = reg[1];
    int rs1 = reg[2];
    int rd = reg[0];
    string rs_2 = as.decimal_To_Binary(rs2);
    string rs_1 = as.decimal_To_Binary(rs1);
    string r_d = as.decimal_To_Binary(rd);
    as.binary_extend(rs_2, 5);
    as.binary_extend(rs_1, 5);
    as.binary_extend(r_d, 5);
    ans += rs_2;
    ans += rs_1;
    ans += as.get_func3(operation);
    ans += r_d;
    ans += as.get_Opcode(operation);

    return ans;
}

string I_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    int immediate;
    immediate = as.get_immediate_addi(line, false);

    string immediate_val = as.decimal_To_Binary(immediate);
    if (operation == "slli" || operation == "srli" || operation == "srai")
    {    cout<<"oper"<<operation<<endl;
        as.binary_extend(immediate_val, 5);
        ans += as.get_funct7(operation);
    }
    else
    {
        as.binary_extend(immediate_val, 12);
    }
    ans += immediate_val;
    vector<int> reg;
    reg = as.get_register(line);
    int rs1 = reg[1];
    int rd = reg[0];
    string rs_1 = as.decimal_To_Binary(rs1);
    string r_d = as.decimal_To_Binary(rd);
    as.binary_extend(rs_1, 5);
    as.binary_extend(r_d, 5);

    ans += rs_1;
    ans += r_d;

    ans += as.get_func3(operation);

    ans += as.get_Opcode(operation);
    return ans;
}

string S_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    int immediate;
    immediate = as.get_immediate_addi(line, true);
    string immediate_val = as.decimal_To_Binary(immediate);
    as.binary_extend(immediate_val, 12);
    ans += immediate_val.substr(0, 7);
    vector<int> reg;
    reg = as.get_register(line);
    int rs1 = reg[1];
    int rd = reg[0];
    string rs_1 = as.decimal_To_Binary(rs1);
    string r_d = as.decimal_To_Binary(rd);
    as.binary_extend(rs_1, 5);
    as.binary_extend(r_d, 5);
    ans += r_d;
    ans += rs_1;
    ans += as.get_func3(operation);
    ans += immediate_val.substr(7, 5);
    ans += as.get_Opcode(operation);
    return ans;
}

string SB_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    int immediate;
    immediate = as.get_immediate_addi(line, false);
    immediate = immediate >> 1;
    string immediate_val = as.decimal_To_Binary(immediate);
    as.binary_extend(immediate_val, 12);
    ans += immediate_val[0];
    ans += immediate_val.substr(2, 6);
    vector<int> reg;
    reg = as.get_register(line);
    int rs1 = reg[1];
    int rs2 = reg[0];

    string rs_1 = as.decimal_To_Binary(rs1);
    string rs_2 = as.decimal_To_Binary(rs2);
    as.binary_extend(rs_1, 5);
    as.binary_extend(rs_2, 5);

    ans += rs_2;
    ans += rs_1;

    ans += as.get_func3(operation);
    ans += immediate_val.substr(8, 4);
    ans += immediate_val[1];
    ans += as.get_Opcode(operation);
    return ans;
}
string UJ_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    int immediate;
    immediate = as.get_immediate_addi(line, false);
    immediate = immediate >> 1;
    string immediate_val = as.decimal_To_Binary(immediate);
    as.binary_extend(immediate_val, 20);
    ans += immediate_val[0];
    ans += immediate_val.substr(10, 10);
    ans += immediate_val[9];
    ans += immediate_val.substr(1, 8);
    vector<int> reg;
    reg = as.get_register(line);
    int rd = reg[0];
    string r_d = as.decimal_To_Binary(rd);
    as.binary_extend(r_d, 5);
    ans += r_d;
    ans += as.get_Opcode(operation);
    return ans;
}
string U_type_addresing_Instr(string &line, string &operation)
{
    ASSEMBLER as;
    string ans = "";
    int immediate;
    immediate = as.get_immediate_addi(line, false);
    string immediate_val = as.decimal_To_Binary(immediate);
    as.binary_extend(immediate_val, 32);
    ans += immediate_val.substr(0, 20);
    vector<int> reg;
    reg = as.get_register(line);
    int rd = reg[0];
    string r_d = as.decimal_To_Binary(rd);
    as.binary_extend(r_d, 5);
    ans += r_d;
    ans += as.get_Opcode(operation);
    return ans;
}

class ASSEMBELY_TO_MACHINE
{
public:
    void print_R_type(string &machine_Code);
    void print_SB_type(const string &machine_Code);
    void print_I_type(const string &machine_Code);
    void print_S_type(const string &machine_Code);
    void print_U_type(const string &machine_Code);
    void print_UJ_type(const string &machine_Code);
    string get_Machine_Code(string &line);
};
void ASSEMBELY_TO_MACHINE::print_R_type(string &machine_Code){
    cout<<"          -----------  R TYPE ------------      "<<endl;
   cout << " funct7 | rs2  | rs1  | funct3 | rd   | opcode" << endl;
    cout << machine_Code.substr(0, 7) << "  |  ";
    cout << machine_Code.substr(7, 5) << "  |  ";
    cout << machine_Code.substr(12, 5) << "  |  ";
    cout << machine_Code.substr(17, 3) << "   |  ";
    cout << machine_Code.substr(20, 5) << "  |  ";
    cout << machine_Code.substr(25, 7) << endl;  
}
void ASSEMBELY_TO_MACHINE::print_SB_type(const string &machine_Code) {
    cout<<"          -----------  SB TYPE ------------      "<<endl;

    cout << "imm[12] | imm[10:5] | rs2  | rs1  | funct3 | imm[4:1] | imm[11] | opcode" << endl;
    cout  << machine_Code[0] << "    |  ";
    cout << machine_Code.substr(1, 6) << "   |  ";
    cout << machine_Code.substr(7, 5) << "  |  ";
    cout << machine_Code.substr(12, 5) << "  |   ";
    cout << machine_Code.substr(17, 3) << "  |  ";
    cout << machine_Code.substr(20, 4) << "   |    ";
    cout << machine_Code[24] << "   |  ";
    cout << machine_Code.substr(25, 7) << endl;
}
void ASSEMBELY_TO_MACHINE:: print_I_type(const string &machine_Code) {
    cout<<"          -----------  I TYPE ------------      "<<endl;
    cout << " imm[11:0] | rs1  | funct3 | rd   | opcode" << endl;
    cout << machine_Code.substr(0, 12) << " |  ";
    cout << machine_Code.substr(12, 5) << "  |   ";
    cout << machine_Code.substr(17, 3) << "   |  ";
    cout << machine_Code.substr(20, 5) << "  |  ";
    cout << machine_Code.substr(25, 7) << endl;
}
void ASSEMBELY_TO_MACHINE:: print_S_type(const string &machine_Code) {
    cout<<"          -----------  S TYPE ------------      "<<endl;
    cout << "imm[11:5] | rs2  | rs1  | funct3 | imm[4:0] | opcode" << endl;
    cout << machine_Code.substr(0, 7) << "  |  ";   // imm[11:5]
    cout << machine_Code.substr(7, 5) << "  |  ";           // rs2
    cout << machine_Code.substr(12, 5) << "  |   ";         // rs1
    cout << machine_Code.substr(17, 3) << "   |  ";         // funct3
    cout << machine_Code.substr(20, 5) << "  |  ";          // imm[4:0]
    cout << machine_Code.substr(25, 7) << endl;             // opcode
}
void ASSEMBELY_TO_MACHINE:: print_U_type(const string &machine_Code) {
    cout<<"          -----------  U TYPE ------------      "<<endl;
    cout << " imm[31:12]        | rd   | opcode" << endl;
    cout << machine_Code.substr(0, 20) << " |  ";    // imm[31:12]
    cout << machine_Code.substr(20, 5) << "  |  ";          // rd
    cout << machine_Code.substr(25, 7) << endl;             // opcode
}
void ASSEMBELY_TO_MACHINE:: print_UJ_type(const string &machine_Code) {
    cout<<"          -----------  UJ TYPE ------------      "<<endl;
    cout << "imm[20] | imm[10:1]  | imm[11] | imm[19:12] | rd   | opcode" << endl;
    cout << machine_Code[0] << "   | ";            // imm[20]
    cout << machine_Code.substr(1, 10) << " |  ";           // imm[10:1]
    cout << machine_Code[11] << "   |  ";                   // imm[11]
    cout << machine_Code.substr(12, 8) << "   |  ";         // imm[19:12]
    cout << machine_Code.substr(20, 5) << "  |  ";          // rd
    cout << machine_Code.substr(25, 7) << endl;             // opcode
}
string ASSEMBELY_TO_MACHINE::get_Machine_Code(string &line)
{
    ASSEMBLER as;
     string operation = as.get_Operation(line);
    string type = as.get_type(operation);
    string machine_Code;
    if (type == "R")
    {
        machine_Code = R_type_addresing_Instr(line, operation);
        print_R_type(machine_Code);
    }
    else if (type == "I")
    {
        machine_Code = I_type_addresing_Instr(line, operation);
        print_I_type(machine_Code);
    }
    else if (type == "S")
    {
        machine_Code = S_type_addresing_Instr(line, operation);
        print_S_type(machine_Code);
    }
    else if (type == "SB")
    {
        machine_Code = SB_type_addresing_Instr(line, operation);
        print_SB_type(machine_Code);
    }
    else if (type == "U")
    {
        machine_Code = U_type_addresing_Instr(line, operation);
        print_U_type(machine_Code);
    }
    else if (type == "UJ")
    {
        machine_Code = UJ_type_addresing_Instr(line, operation);
        print_UJ_type(machine_Code);
    }
    return machine_Code;
}
void read_assembly_write_machine(const string &filename,ofstream &outFile){
    ASSEMBELY_TO_MACHINE check;
    ifstream inputFile(filename);
      if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return;
    }
    string line;
    while(getline(inputFile,line)){
        stringstream ss(line);
          string machine_code= check.get_Machine_Code(line);
        outFile << machine_code << " ";
        outFile << endl;
    }
     inputFile.close();
}
int main()
{ ofstream outFile("machine.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening output file: machine.txt" << endl;
        return 1;
    }
    read_assembly_write_machine("assembly.txt", outFile);
    outFile.close();
}