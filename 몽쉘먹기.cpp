#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n, k, temp, count = 0;
	queue<int> q1;

	cin >> n >> k;

	for (int i = 1; i < n + 1; i++)
		q1.push(i);

	while (q1.size() != 1)
	{
		for (int i = 1; i < k + 1; i++)
		{
			if (i != k) q1.push(q1.front());
			q1.pop();
		}
	}
	cout << q1.front();
}