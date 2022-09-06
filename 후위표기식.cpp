#include <iostream>
#include <stack>
#include <string>

using namespace std;

int a = 0, b = 0, result = 0;
stack<int> s1;

void AbPop()
{
	b = s1.top();
	s1.pop();
	a = s1.top();
	s1.pop();
}

int main(void)
{
	string temp;

	cin >> temp;

	for (int i = 0; i < temp.size(); i++)
	{
		switch (temp[i])
		{
		case '+':
			AbPop();
			result = a + b;
			s1.push(result);
			break;
		case '-':
			AbPop();
			result = a - b;
			s1.push(result);
			break;
		case '*':
			AbPop();
			result = a * b;
			s1.push(result);
			break;
		case '/':
			AbPop();
			result = a / b;
			s1.push(result);
			break;
		default:
			s1.push(temp[i] - '0');
			break;
		}
	}

	cout << s1.top();
	s1.pop();
}