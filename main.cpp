#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include"Archiver.h"
using namespace std;

int main()
{
	Archiver a;
	size_t n = 0;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		a.toBin(n++, i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		a.toBin(n++, i);
	}
	a.punctuation_marks();
	string in;
	cout << "Enter name input file" << endl;
	cin >> in;
	string code;
	a.load(in, code);
	string code1;
	a.lengthstring(code1, code);
	vector <bool> code2;
	a.lengthbool(code2, code1);
	string in1;
	cout << "Enter file name to archive" << endl;
	cin >> in1;
	a.coding(in1, code2);
	string code3;
	string in2;
	cout << "Enter file name to unzip" << endl;
	cin >> in2;
	a.decoding(in2, code3);
	string in3;
	cout << "Enter name file to save" << endl;
	cin >> in3;
	a.print(in3, code3);
	return 0;
}


