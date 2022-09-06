#include <iostream>
using namespace std;

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;

	int num = 0;

	int parkIn[100] = {0,};
	int parkOut[100] = {0,};

	int high = 0;
	int numCheck = 0;
	int result = 0;

	cin >> a >> b >> c;
	
	for (int i = 0; i < 3; i++)
	{
		cin >> num;
		parkIn[i] = num;
		cin >> num;
		parkOut[i] = num;
		if (num > high)
			high = num;
	}
	
	for (int i = 0; i < high; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (parkIn[j] <= i + 1)
			{
				if (parkOut[j] > i + 1)
					numCheck++;
			}
		}

		switch (numCheck)
		{
		case 1:
			result += numCheck * a;
			break;
		case 2:
			result += numCheck * b;
			break;
		case 3:
			result += numCheck * c;
			break;
		}
		numCheck = 0;
	}

	cout << result;
}