#include <iostream> 
#include<process.h>
using namespace std;
void decToBinary(int n,int base)
{
	int storenum[32], temp;
	char storehex[100];
	int i = 0;
	while (n > 0) {
		if (base == 16)
		{
			temp = n % base;
			if (temp < 10)
			{
				storehex[i] = temp + 48;
				//i++;
			}
			else
			{
				storehex[i] = temp + 55;
				//i++;
			}
		}
		else
			storenum[i] = n % base;
		n = n / base;
		i++;
	}

	
	
		for (int j = i - 1; j >= 0; j--)
		{
			if (base != 16)
				cout << storenum[j];
			else
				cout << storehex[j];
		}
		
}
void todecimal(char *n, int base)
{
	int temp, number, len;
	len = strlen(n);
	number = 0;
	for (int i = 0;i<len; i++)
	{
		if (n[i] >= 48 && n[i] <= 57)
		{
			temp = n[i] - 48;
		}
		else
		{
			temp = n[i] - 55;
		}
		number += temp * pow(base, len-1-i);
		//cout << number;
	}
	cout << number;
}


int main()
{
	int n,base;
	char hexn[100];
	cout << "Enter the number to convert : ";
	cin >> n;
	cout << "\nBinary : ";
	decToBinary(n,2);
	cout << "\nOctal : ";
	decToBinary(n, 8);
	cout << "\nHexadecimal : ";
	decToBinary(n, 16);
	cout << "\nEnter the number to convert to decimal : ";
	cin >> hexn;
	cout << "Enter the base of the number (2,8,16) : ";
	cin >> base;
	todecimal(hexn, base);
	system("pause");

	return 0;
}