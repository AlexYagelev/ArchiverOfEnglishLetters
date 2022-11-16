
#include"Archiver.h"
using namespace std;
size_t K = 6;


void Archiver::toBin(size_t a, char i)
{
	string res = "";
	while (a > 0)
	{
		res += ((a % 2) + '0');
		a /= 2;
	}
	while (res.size() < K)
		res += '0';
	string r = "";
	for (int i = res.length() - 1; i >= 0; i--)
	{
		r = r + res[i];
	}
	res = r;
	this->alphabet[i] = res;

}

void Archiver::load(const string& filename, string& code)
{
	ifstream f1;
	string f2;
	f1.open(filename);
	while (!f1.eof())
	{
		f2 = "";
		getline(f1, f2);
		code = code + f2;
	}
	f1.close();
}
void Archiver::lengthstring(string& code1, string& code)
{
	string q;
	for (int i = 0; i < code.length(); i++) //ïðîõîäèì ïî ñòðîêå è âûâîäèì 0 è 1
	{
		char c = code[i];
		map<char, string> ::iterator itr;
		for (itr = this->alphabet.begin(); itr != this->alphabet.end(); itr++)
		{
			if (c == itr->first)
			{
				q = itr->second;
				code1 = code1 + q;
				q.clear();
				break;
			}
		}
	}
	//cout << code1 << endl;
}
void Archiver::lengthbool(vector <bool>& code2, string& code1)
{
	for (int i = 0; i < code1.length(); i++) //ïðîõîäèì ïî ñòðîêå è âûâîäèì 0 è 1
	{
		if (code1[i] == '0')
		{
			code2.push_back(0);
		}
		if (code1[i] == '1')
		{
			code2.push_back(1);
		}
	}
	while (code2.size() % 8 != 0)
	{
		code2.push_back(1);
	}
	/*
	for (int i = 0; i < code2.size(); i++)
	{
		cout << code2[i];
	}
	cout << endl;
	cout << code2.size();
	*/

}
void Archiver::coding(const string& filename1, vector <bool>& code2)
{
	ofstream g(filename1, ios::out | ios::binary);
	int count = 0;
	char buf = 0;
	int j = 0;
	for (int n = 0; n < code2.size(); n++)
	{
		buf = buf | code2[n] << (7 - count);
		count++;
		if (count == 8)
		{
			count = 0;
			g << buf;
			buf = 0;
		}
	}
	g.close();
}
void Archiver::decoding(const string& filename3, string& code3)
{
	ifstream F;
	F.open(filename3);
	int count = 0;
	string x;
	string y;
	char byte;
	byte = F.get();
	vector<bool> t;
	while (!F.eof())
	{
		bool b = byte & (1 << (7 - count));
		if (b == 0)
			t.push_back(0);
		if (b == 1)
			t.push_back(1);
		count++;
		if (count == 8)
		{
			for (int i = 0; i < t.size(); i++)
			{
				if (t[i] == 0)
				{
					x = "0";
				}
				if (t[i] == 1)
				{
					y = "1";
				}
				code3 = code3 + x + y;
				x.clear();
				y.clear();
			}
			t.clear();
			count = 0;
			byte = F.get();
		}
	}
	F.close();
	//cout << code3;
}

void Archiver::print(const string& filename4, string& code3)
{
	ofstream ne;
	ne.open(filename4);
	int count = 0;
	string c;
	for (int i = 0; i < code3.length(); i++)
	{
		c = c + code3[i];
		map<char, string> ::iterator itr;
		if (c.size() == 6)
		{
			for (itr = this->alphabet.begin(); itr != this->alphabet.end(); itr++)
			{
				if (c == itr->second)
				{
					ne << itr->first;
					c.clear();
					break;
				}
			}
		}
	}
	ne.close();
}
void Archiver::punctuation_marks() {
	this->alphabet[' '] = "110100";
	this->alphabet['!'] = "110101";
	this->alphabet[','] = "110110";
	this->alphabet['.'] = "110111";
	/*
	map<char, string> ::iterator itr;
	for (itr = alphabet.begin(); itr != alphabet.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
	*/
}
