#include <iostream>
using namespace std;

int main(void)
{
	// 1�ܰ� ����
	/*
	int arr[10][10] = { 0, };
	int temp = 0;
	
	for (int i = 0; i < 10; i++)
		arr[i][0] = 1;

	// i ���� j ����

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i > 0 && j > 0)
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			if (arr[i][j] != 0)
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// 2�ܰ� ����
	/*
	int arr[100] = { 0, };

	for (int i = 0; i < 10; i++)
		arr[i * 10] = 1;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i > 0 && j > 0)
				arr[i* 10 + j] = arr[i * 10 - 10 + j] + arr[i * 10 - 10 + j - 1];
			if (arr[i * 10 + j] > 0)
				cout << arr[i * 10 + j] << " ";
		}
		cout << endl;
	}
	*/
}