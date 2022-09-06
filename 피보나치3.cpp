#include <iostream>
using namespace std;

int main(void)
{
	int arr[10000] = { 1, 1, 0,};
	int result = 0;
	int n = 0;
	int temp = 0;

	while (true)
	{
		cin >> n;
		temp = n;
		if (arr[n] == 0)
		{
			while (true)
			{
				if (arr[temp - 2] == 0 || arr[temp - 1] == 0)
					temp--;
				else
					break;
			}
			for (temp; temp <= n; temp++)
			{
				arr[temp] = arr[temp - 1] + arr[temp - 2];
			}
		}

		result = arr[n-1];
		cout << result << endl;
		result = 0;
		temp = 0;
	}
}