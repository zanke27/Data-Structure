#include <iostream>
using namespace std;

int main(void)
{
	const int NUM = 100;
	char arr[4][NUM] = { "",};
	// char ���� ���ڿ� �ڿ� NULL�ϳ��� ����
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = NUM - 1; j >= 0; j--)
			cout << arr[i][j];
		cout << endl;
	}
}