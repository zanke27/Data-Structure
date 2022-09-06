#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> s1;
	stack<char> outS;
	string result = "";

	int check = 0, i = 0, n = NULL;

	cin >> i;
	while (check <= i)
	{
		cin >> n;
		s1.push(n);
		result += 'P';
		if (check == 0 || s1.top() < n)
		{
			s1.pop();
			result += 'O';
			check++;
		}
		check++;
	}

	cout << result;
}