#include <iostream>
using namespace std;

int main(void)
{
	const int NUM = 100;
	char arr[4][NUM] = { "",};
	// char 형은 문자열 뒤에 NULL하나가 있음
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = NUM - 1; j >= 0; j--)
			cout << arr[i][j];
		cout << endl;
	}
}