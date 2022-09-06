#include <iostream>
using namespace std;

class Queue
{
public:
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;

	void InitQueue(int qsize)
	{
		buf = new int[qsize]; // 동적으로 배열 할당하는 법
		front = -1;
		rear = -1;
		count = 0;
	}
	void Enqueue(int data)
	{
		if (IsFull() != 1)
		{
			rear += 1;
			buf[rear] = data;
			count += 1;
		}
	}
	int Dequeue()
	{
		front += 1;
		count -= 1;
		return buf[front];
	}
	int IsFull()
	{
		if (qsize == count)
		{
			cout << "큐가 꽉 찼음 \n";
			return 1;
		}
	}
	int IsEmpty()
	{
		if (count == 0)
		{
			cout << "큐가 비어있음\n";
			return 1;
		}
		else
			return 0;
	}
};

int main(void)
{
	int i;
	Queue q1;
	q1.InitQueue(10);
	for (i = 1; i <= 11; i++)
	{
		cout << i << " 입력\n";
		q1.Enqueue(i);
	}
	cout << endl;

	while (!q1.IsEmpty())
		cout << q1.Dequeue() << " 출력 \n";
	cout << endl;
	return 0;
}