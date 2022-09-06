#include <iostream>
using namespace std;

int main(void)
{
	int n = 0;
	int m = 0;

	int* arr;

	int result = 0;

	cin >> n;
	cin >> m;
	arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == m)
				result++;
		}
	}

	cout << result;
}