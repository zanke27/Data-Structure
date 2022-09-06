#include <iostream>
using namespace std;

int ReceiveAndCompare(int temp, int result, int count)
{
	if (count == 0)
		return result;

	cin >> temp;
	if (result < temp)
		result = temp;

	return ReceiveAndCompare(temp, result, count-=1);
}

int main(void)
{
	int temp = 0;
	int result = 0;
	int count = 5;
	cout << endl << "제일 큰 수는 " << ReceiveAndCompare(temp, result, 5);
}