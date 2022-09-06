#include <iostream>
#include <stack>	
#include <string>

using namespace std;

int main(void)
{
	int count = 0;
	string temp;
	stack<int> s1;
	stack<int> s2;
	stack<int> s3;

	cin >> temp;

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '(')
			s1.push(count);
		else if (temp[i] == ')')
			s1.pop();
	}
	
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '[')
			s2.push(count);
		else if (temp[i] == ']')
			s2.pop();
	}

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '{')
			s3.push(count);
		else if (temp[i] == '}')
			s3.pop();
	}

	if (s1.empty() && s2.empty() && s3.empty())
	{
		cout << "괄호 검사 성공";
		return 0;
	}

	cout << "괄호 검사 실패";
}