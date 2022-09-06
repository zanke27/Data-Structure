#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	int count = 0;
	string temp;
	stack<int> s1;

	cin >> temp;

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '(')
		{
			count++;
			s1.push(count);
			cout << count;
		}
		else if (temp[i] == ')')
		{
			cout << s1.top();
			s1.pop();
		}
	}
	
}