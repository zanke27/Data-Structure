#include <iostream>
using namespace std;

int main(void)
{
	int* arr;
	int* score;
	int n = 0;

	int num = 0;
	int checkUp = 0;

	int result = 0;

	cin >> n;
	arr = new int[n];
	score = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		score[i] = num;
	}

	for (int i = 0; i < n; i++)
	{
		checkUp = 0;
		for (int j = 0; j < n; j++)
		{
			if (score[i] < score[j])
				checkUp++;
		}
		cout << checkUp + 1 << " ";
	}
}