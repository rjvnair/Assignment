//1.	Check whether a given number is an Adam number
#include<iostream>
using namespace std;

int reverse(int num)
{
	int rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return rev;
}
int square(int num)
{
	return(num*num);
}
bool checkadam(int num)
{
	if (square(num) == reverse(square(reverse(num))))
		return true;
	else
		return false;

}
int main()
{
	int n;
	cout << "Enter the number : ";
	cin >> n;
	//cout << "fd";
	if(checkadam(n))
		cout << n << " is an adam number";
	else
		cout << n << " is not an adam number";

	return 0;
}