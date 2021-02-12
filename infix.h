/*
	The header file contains the class "Infix" that hosts 
	the various public functions and two private objects. 
		=> The public functions perform different operations 
			as specified in the implimentationfile. 
		=> The two private objects hold the stack of operators, 
			symbols and intiger numbers. 
		=> Symbols and operators go to "sym" stack and integers go to "op" stack. 
	Precondition: - The program works for single digit integers and operation that 
					involves infix expressions. 
	Postcondition: - The program will read a file that has infix expressions, 
					 read the expressions one line at a time, displays the 
					 line of expression, computes the expression, and displays
					 the value of the expression. 
*/
#include <iostream>
#ifndef _INFIX
#define _INFIX
#include <bits/stdc++.h> 	//required header file by the stack operation. 
using namespace std; 
class Infix{				
	private:				 
		stack <char> sym;	//holds symbols and operators.
		stack <int> op;		//holds integer operands.
	public:
		void doStack(string, int); 	//function to perform the infix stack operation.
		int doComputations(char, int, int); //function to perform the computations
		void processLine();		//function to read file and process it as an array.
		void formNumStack(int);		//function to form the operannd stack
		void formSymStack(char);	//function to form the operator and braces. 
		int getOperand();			//function to pop and return operands.
		char getOperator();			//function to pop and return operators.
		int comparPrecedence(char);	//function to compare precedence of operators.
};
#endif
