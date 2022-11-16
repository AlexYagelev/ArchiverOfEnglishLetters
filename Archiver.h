#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Archiver
{
private:
	map<char, string> alphabet;
public:
	void load(const string& filename, string& code);
	void coding(const string& filename1, vector <bool>& code2);
	void decoding(const string& filename3, string& code3);
	void print(const string& filename4, string& code3);
	void lengthstring(string& code1, string& code);
	void lengthbool(vector <bool>& code2, string& code1);
	void toBin(size_t a, char i);
	void punctuation_marks();
};
