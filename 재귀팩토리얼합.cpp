#include <iostream>
using namespace std;

int Factorial(int num)
{
	if (num == 1)
		return 1;
	else
		return num * Factorial(num - 1);
}

int SumNumber(int num)
{
	if (num == 1)
		return 1;
	else
		return num + SumNumber(num-1);
}

int main(void)
{
	cout << Factorial(5) << endl;
	cout << SumNumber(5) << endl;
}