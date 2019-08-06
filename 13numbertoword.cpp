#include<iostream>
#include<process.h>
#include<string>
using namespace std;
class digit
{
public:
	 
	string	single_digits[10] = { "zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine " };
	string two_digits[11] = { "", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ","fifteen ", "sixteen ","seventeen ", "eighteen ", "nineteen " };
	string tens_multiple[10] = { "", "", "twenty ", "thirty ", "forty ", "fifty ","sixty ", "seventy ", "eighty ", "ninety " };
	string tens_power[2] = { "hundred ", "thousand " };

	void threedigit(char *, int, int);
	void twodigit(char *, int, int);
	void word(char *, int);
};
void digit::threedigit(char *num, int i, int j)
{
	if (num[i] != '0')
	{
		int k = num[i] - '0';
		cout << single_digits[k] << "hundred ";
	}
	twodigit(num,i - 1, j);
}
void digit::twodigit(char *num, int i, int j)
{

	if (num[i] == '1')
	{
		int sum = num[i] - '0' + num[j] - '0';
		cout << two_digits[sum];
	}
	else if (num[i] != '0'&&num[j] == '0')
	{
		int k = num[i] - '0';
		cout << tens_multiple[k];
	}
	else
	{
		int k = num[i] - '0';
		cout << tens_multiple[k];
		int l = num[j] - '0';
		cout << single_digits[l];
	}
}
void digit::word(char *num, int len)
{
	int i,j=0,k;
	i = len ;
	k = len + 1;
	
	while (k != 0)
	{
		j = k % 7;
		if (j == 1)
		{
			int l = num[i] - '0';
			cout << single_digits[l];
			if (k > 7)
				cout << "Crore ";
			i--;
			
		}
		else if (j == 2)
		{
			twodigit(num, i, i - 1);
			i -= 2;
			cout << "crore";

		}
		else if (j == 3)
		{
			threedigit(num, i, i - 2);
			i = i - 3;
			if(len>3)
			cout << "Crore ";
		}
		else if (j == 4)
		{
			int l = num[i] - '0';
			cout << single_digits[l] << " thousand ";
			i = i--;
			threedigit(num, i, i - 2);
			i -= 3;
			//cout << "crore";
		}	
		else if (j == 5)
		{
			twodigit(num, i, i - 1);
			cout << "Thousand ";
			i = i - 2;
			threedigit(num, i, i - 2);
			i -= 3;
			//cout << "crore";
		}
		else if (j ==6)
		{
			//twodigit(num, i, i - 1);
			//cout << "Lakhs ";
			//i = i - 2;
			int l = num[i] - '0';
			cout << single_digits[l];
			cout << "Lakhs ";
			i--;
			twodigit(num, i, i - 1);
			cout << "Thousand ";
			i = i - 2;
			threedigit(num, i, i - 2);
			i -= 3;
			cout << "crore";
		}
		else if(j==0)
		{
			/*threedigit(num, i, i - 2);
			cout << "Crore ";
			i -= 3;*/
			twodigit(num, i, i - 1);
			cout << "Lakhs ";
			i = i - 2;
			twodigit(num, i, i - 1);
			cout << "Thousand ";
			i = i - 2;
			threedigit(num, i, i - 2);
			i -= 3;
			
		}
		if (j < 7)
		{
			k -= j;
		}
		else
		{
			k -= 7;
		}
	}
}
/*void digit::word(char *num, int len)
{
	for (int i = 0; i <= len;)
	{
		threedigit(num, i + 2, i);
		i += 3;
		twodigit(num, i + 1, i);
		i += 2;
		twodigit(num, i + 1, i);
		i += 2;
	}
	
}*/

int main()
{
	char num[15];
	digit x;
	int len;
	while (!NULL)
	{
		cout << "\nEnter the number:";
		cin >> num;
		len = strlen(num);
		if (num[0] == '-')
		{
			_strrev(num);
			num[len - 1] = '-';
			cout << "-";
		}
		else if (num[0] == '+')
		{
			_strrev(num);
			num[len - 1] = '+';
			cout << "+";
		}
		else
		{
			_strrev(num);
			num[len] = '+';
			cout << "+";
		}
		x.word(num, len - 1);
	}
	system("pause");
	return 0;
}




