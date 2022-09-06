#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}

	for (auto i : vec)
	{
		cout << i << " ";
	}
}