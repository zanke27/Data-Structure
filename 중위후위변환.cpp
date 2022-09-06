#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	stack<char> huwiStack;
	stack<char> yunsanStack;

	stack<char> reverseStack;

	string temp;
	int count = 0;

	cin >> temp;

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] - '0' > 0 && temp[i] - '0' < 10)
			cout << temp[i];
		else if (yunsanStack.empty())
			yunsanStack.push(temp[i]);
		else if (!yunsanStack.empty())
		{
			if (yunsanStack.top() == '/' || yunsanStack.top() == '*')
			{
				cout << yunsanStack.top();
				yunsanStack.pop();
				yunsanStack.push(temp[i]);
			}
			else if (yunsanStack.top() == '+' || yunsanStack.top() == '-')
			{
				if (temp[i] == '/' || temp[i] == '*')
					yunsanStack.push(temp[i]);
				else if (temp[i] == '+' || temp[i] == '-')
				{
					cout << yunsanStack.top();
					yunsanStack.pop();
					yunsanStack.push(temp[i]);
				}
			}
		}
		count++;
	}
	
	while (true)
	{
		if (!yunsanStack.empty())
		{
			cout << yunsanStack.top();
			yunsanStack.pop();
		}
		else
		{
			break;
		}
	}
}