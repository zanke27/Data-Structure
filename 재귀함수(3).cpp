#include <iostream>
using namespace std;

int GreatestCommonFactor(int a, int b)
{
	int temp = 0;
	temp = a % b;
	
	if (temp == 0)
		return b;

	return GreatestCommonFactor(b, temp);
}

int main(void)
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << endl << "최대공약수는 " << GreatestCommonFactor(a, b);
}