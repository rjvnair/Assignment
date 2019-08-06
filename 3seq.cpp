#include<iostream>
#include<string>
#include<process.h>
using namespace std;
bool checkPattern(string str, string pattern)
{
	int len = pattern.length();
	if (str.length() < len)
		return false;

	for (int i = 0; i < len - 1; i++)
	{
		char x = pattern[i];
		char y = pattern[i + 1];
		size_t last = str.find_last_of(x);
		size_t first = str.find_first_of(y); 
		if (last == string::npos || first ==
			string::npos || last > first)
			return false;
	}
	return true;
}


int main()
{
	string str, pattern;
	cout << "Enter the first string(pattern) : ";
	getline(cin, pattern);
	cout << "Enter the second string : ";
	getline(cin, str);
	if (checkPattern(str, pattern))
		cout << "The string follows the pattern. ";
	else
		cout << "The string doesnt follow the pattern. ";
	system("pause");
	return 0;
}