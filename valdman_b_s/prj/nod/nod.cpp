#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int firstNumber = a;
	int secondNumber = b;

	int c;
	while (secondNumber)
	{
		c = firstNumber % secondNumber;
		firstNumber = secondNumber;
		secondNumber = c;
	}

	return(firstNumber);
}

int main()
{
	cout << gcd(144, 60);
	cout << gcd(77, 77);
	cout << gcd(-11, 77);
	cout << gcd(-12, -4);
	system("pause");
}