#include <iostream>
using namespace std;

long long Factorial(long long num)
{
	if (num == 1)
		return 1;
	else
		return num * Factorial(num - 1);
}

int Combination(int n, int r)
{
	int temp = n - r;
	long long result = Factorial(r) * Factorial(temp);
	result = Factorial(n) / result;
	return result;
}

int main(void)
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << endl << Combination(a, b);
}