#include<bits/stdc++.h>
#include<string>
#include <iostream>

using namespace std;

string binary_to_hexadecimal(int binaryNum)
{
    int hex=0, mul=1, chk=1, rem, i=0;
    string hexDecNum = "";
    for(int j = 0; j < (to_string(binaryNum)).length() / 4; j++)
    	hexDecNum+= " ";
    while(binaryNum!=0)
    {
        rem = binaryNum%10;
        hex = hex + (rem*mul);
        if(chk%4==0)
        {
            if(hex<10)
                hexDecNum[i] = hex+48;
            else
                hexDecNum[i] = hex+55;
            mul = 1;
            hex = 0;
            chk = 1;
            i++;
        }
        else
        {
            mul = mul*2;
            chk++;
        }
        binaryNum = binaryNum/10;
    }
    if(chk!=1)
        hexDecNum[i] = hex+48;
    if(chk==1)
        i--;
	reverse(hexDecNum.begin(), hexDecNum.end());
	return hexDecNum;
}
string find_reg(string reg){
	if(reg == "al" || reg == "ax" || reg == "eax")
		return "000";
		
	else if(reg == "cl" || reg == "cx" || reg == "ecx")
		return "001";
	
	else if(reg == "dl" || reg == "dx" || reg == "edx")
		return "010";
		
	else if(reg == "bl" || reg == "bx" || reg == "ebx")
		return "011";
		
	else if(reg == "ah" || reg == "sp" || reg == "esp")
		return "100";
		
	else if(reg == "ch" || reg == "bp" || reg == "ebp")
		return "101";
	
	else if(reg == "dh" || reg == "si" || reg == "esi")
		return "110";
		
	else if(reg == "bh" || reg == "di" || reg == "edi")
		return "111";
}
string add(string operand1, string operand2){
	string opcode;
	if(operand1[1] == 'h' || operand1[1] == 'l')                              // reg8
		opcode = "02";
	else																	// reg16/32
		opcode = "03";		
	return opcode;												
}
string sub(string operand1, string operand2){
	string opcode;
	if(operand1[1] == 'h' || operand1[1] == 'l')                              // reg8
		opcode = "2A";
	else																	// reg16/32
		opcode = "2B";		
	return opcode;												
}
string Or(string operand1, string operand2){
	string opcode;
	if(operand1[1] == 'h' || operand1[1] == 'l')                              // reg8
		opcode = "0A";
	else																	// reg16/32
		opcode = "0B";		
	return opcode;												
}
string And(string operand1, string operand2){
	string opcode;
	if(operand1[1] == 'h' || operand1[1] == 'l')                              // reg8
		opcode = "22";
	else																	// reg16/32
		opcode = "23";		
	return opcode;												
}
string assemble(string operation ,string operand1, string operand2){
	string ans = "";
	string secondbyte = "11" + find_reg(operand1) + find_reg(operand2);
	int binary_num = stoi(secondbyte);
	if(operation == "add"){
		ans += add(operand1, operand2);
	}
	else if(operation == "sub"){
		ans += sub(operand1, operand2);
	}
	else if(operation == "and"){
		ans += And(operand1, operand2);
	}
	else if(operation == "or"){
		ans += Or(operand1, operand2);
	}
	ans += " " + binary_to_hexadecimal(binary_num);

	
	if(operand1[1] == 'x' || operand1 == "si" || operand1 == "di" || operand1 == "bp" || operand1 == "sp")
		ans = "66 "+ ans;

	return ans;
}
int main() {
	string operation;
	string operand1;
	string operand2;

	cout << "Please Enter your operation: ";
		cin >> operation;
	cout << "Please Enter your first operand: ";
		cin >> operand1;	
	cout << "Please Enter your second operand: ";
		cin >> operand2;
	transform(operation.begin(), operation.end(), operation.begin(), ::tolower); // to lowercase
	transform(operand1.begin(), operand1.end(), operand1.begin(), ::tolower);
	transform(operand2.begin(), operand2.end(), operand2.begin(), ::tolower);
	cout << assemble(operation, operand1, operand2);

}
