#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> q1;

	int temp = 0;
	cin >> temp;

	q1.push(1);
	q1.push(1);

	for (int i = 0; i < temp; i++)
	{
		q1.push(q1.front() + q1.back());
		cout << q1.front();
		q1.pop();
		cout << endl;
	}
	
	

	return 0;
}