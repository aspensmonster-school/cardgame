/*
  Name: Hazlewood_hello.cpp
  Author: Carol Hazlewood
  Date: 09/09/08 17:33
  Description:
        single source file for simple 2-step makefile
*/

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
    ofstream outFile;
    
    outFile.open("Hazlewood_hello.txt");
    
    outFile <<  "hello, world." ; 

    cout << "Hello, World!" << endl;
   
    outFile.close();
    
	cout << "Press ENTER to Continue." << endl;
	cin.get();
    return 0;
}
