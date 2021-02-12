/* 
	This is the implementation file. It contains all 
	the methods/functions that perform various operations.

*/
#include <iostream>
#include "infix.h" 
#include <fstream>
#include <string>
using namespace std; 
int MAX = 100;
Infix S;

void Infix::doStack(string str, int n){
	char ch, c, oprt;
	bool comp;
	int m, oprnd1, oprnd2, result;
	for(int i = 0; i < n; i++){
		c = str[i];
		// if the char read is whitespace,do nothing.
		if(c == ' ')		
			continue;
		//if the char read is a left brace, push it to operator stack
		else if(c == '('){
			S.formSymStack(c);
		}
		//if char read is a digit, push it to operand stack
		else if(isdigit(c) == true){
			m = 0;
			while(i < str.length() && isdigit(str[i])) { //while still reading char of a digit 
				m = (m*10) + (str[i] - '0'); //adjust the number place and convert char to int.
				i++; 
			} 
			S.formNumStack(m);
		}
		//if char read is a right brace, pop the operand stack
		//twice and the operator stack once and perform the operation.
		else if(c==')'){
			while(!S.sym.empty()&& S.sym.top()!='('){
				oprnd1 = S.getOperand();
				oprnd2 = S.getOperand();
				oprt = S.getOperator();
				result = S.doComputations(oprt, oprnd1, oprnd2);
				S.formNumStack(result);
			}
			//pop off the left brace upon exiting the while loop.
			if(!S.sym.empty()){
				S.sym.pop();
			}
		}
		else{
			//compare operators and perform operations according to their precedence.
			while(!S.sym.empty() && (comparPrecedence(S.sym.top())>=comparPrecedence(c))){
				oprnd1 = S.getOperand();
				oprnd2 = S.getOperand();
				oprt = S.getOperator();
				result = S.doComputations(oprt, oprnd1, oprnd2);
				S.formNumStack(result);
			}
			//if precedence comparson is false, push the operator 
			//on the operator stack.
			S.formSymStack(c);
		}
	}
	//if the operator stack is not empyty, perform operations. 
	while(!S.sym.empty()){
		oprnd1 = S.getOperand();
		oprnd2 = S.getOperand();
		oprt = S.getOperator();
		result = S.doComputations(oprt, oprnd1, oprnd2);
		S.formNumStack(result);
	}
	result = S.getOperand();	//final result for each expression
	cout<<" Value = "<< result << endl;
	cout<<"\n";
}
int Infix::doComputations(char oprnd, int oprt1, int oprt2){
	if(oprnd == '+')
		return oprt1 + oprt2;
	else if(oprnd == '-')
		return oprt2 - oprt1;
	else if(oprnd == '*')
		return oprt1 * oprt2;
	else if(oprnd == '/')
		return oprt2 / oprt1;
}
int Infix::comparPrecedence(char s){
	if(s == '+'||s == '-') 
		return 1; 			//low precedence for + & -.
	if(s == '*'||s == '/')  
		return 2; 			//high precedence for * & /.
	return 0; 				//for all other cases, there will be no precedence.
}
void Infix::formNumStack(int n){	
	S.op.push(n);		//push numbers to operand stack.
}
void Infix::formSymStack(char ch){	
	//push symbols and operators to operator stack.	
	S.sym.push(ch);		 
}
int Infix::getOperand(){
	int num = S.op.top();	//get an operand.
	S.op.pop();
	return num;
}
char Infix::getOperator(){
	char c = S.sym.top();	//get an operator.
	S.sym.pop();
	return c;
}
void Infix::processLine(){
	string ch;
	int len, i, j;
	char arr[MAX];
	ifstream file("C:\\Users\\taded\\Documents\\Desktop\\infix.dat"); 
	if (!file)
		cout << " File not found!" << endl;
	else{
		while(!file.eof()){		//read file until end of file.
			getline(file, ch);	// get one line of the file.
			cout<<" Expresion: "<< ch << endl; 
			len = ch.length();
			S.doStack(ch, len); // process the line of expression.
		}
	file.close();
	}
} 
