#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num = 0;
	int pow = 1;
	string s = "";
	string temp = "";
	stack<int> stk;

	cin >> temp;
	s = temp;

	while (s.length() > 0)
	{
		if (s[0] >= '0' && '9' >= s[0])
		{
			stk.push((int)s[0] - '0');
			s.erase(0, 1);
		}
		else if (s[0] == 'z')
		{
			stk.push(0);
			s.erase(0, 4);
		}
		else if (s[0] == 'o')
		{
			stk.push(1);
			s.erase(0, 3);
		}
		else if (s[0] == 't')
		{
			if (s[1] == 'w')
			{
				stk.push(2);
				s.erase(0, 3);
			}
			else
			{
				stk.push(3);
				s.erase(0, 5);
			}
		}
		else if (s[0] == 'f')
		{
			if (s[1] == 'o')
			{
				stk.push(4);
				s.erase(0, 4);
			}
			else
			{
				stk.push(5);
				s.erase(0, 4);
			}
		}
		else if (s[0] == 's')
		{
			if (s[1] == 'i')
			{
				stk.push(6);
				s.erase(0, 3);
			}
			else
			{
				stk.push(7);
				s.erase(0, 5);
			}
		}
		else if (s[0] == 'e')
		{
			stk.push(8);
			s.erase(0, 5);
		}
		else if (s[0] == 'n')
		{
			stk.push(9);
			s.erase(0, 4);
		}
	}

	while (!stk.empty())
	{
		num += stk.top() * pow;
		pow *= 10;
		stk.pop();
	}
	cout << num;
}