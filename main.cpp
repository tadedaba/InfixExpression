/*
	This is the main method. It contains the testing
	function for the implementation. It calls one function 
	from the implementation to perform the duty.
*/
#include <iostream>
#include <string>
#include "infix.h"
#include "infix.cpp"
using namespace std;
int main(int argc, const char * argv[]){
	string input;
	Infix myfile;
	cout<<" This program will read a line of\n" 
		" expression from a file and perform an\n"
		" infix operation on the line of expression"<<endl;
	cout<<"========================================"<<endl;
	cout << " Enter input file name: ";
	cin >> input;
	cout<<"\n";
	if(input == "infix.dat"){
		myfile.processLine();
		cout << "End of file!"<<endl;
	}
	else
		cout << "File Name does not Exist." << endl;
	return 0;
}

