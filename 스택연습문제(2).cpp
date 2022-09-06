#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	int index = 0;
	int count = 0;
	int comTime = 0;

	stack<char> s1;

	char num[500] = { NULL, };

	cin >> num;

	for (int i = 0; i < 500; i++)
	{
		if (num[i] == NULL)
			break;
		index++;
	}

	for (int i = index-1; i >= 0; i--)
	{
		s1.push(num[i]);
		comTime += 1;
		if (comTime == 3 && i != 0)
		{
			comTime = 0;
			s1.push(',');
			count++;
		}
	}

	for (int i = 0; i < index + count; i++)
	{
		cout << s1.top();
		s1.pop();
	}
}