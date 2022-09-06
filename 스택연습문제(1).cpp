#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	const int SIZE = 50;

	stack<string> stack1;

	string array1[SIZE];
	string temp = "";
	
#pragma region 1단계
	
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		array1[i] = temp;
	}
	for (int i = 2; i >= 0; i--)
	{
		reverse(array1[i].begin(), array1[i].end());
		stack1.push(array1[i]);
	}

#pragma endregion

#pragma region 2단계

	//for (int i = 0; i < 3; i++)
	//{
	//	cin >> temp;
	//	array1[i] = temp;
	//	reverse(array1[i].begin(), array1[i].end());
	//	stack1.push(array1[i]);
	//}

#pragma endregion

	while (!stack1.empty())
	{
		cout << stack1.top() << endl;
		stack1.pop();
	}
	
}