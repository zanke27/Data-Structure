#include <iostream>
using namespace std;

class Queue
{
public:
	int* buf;
	int qsize;
	int front;
	int rear;

	void InitQueue(int qsize)
	{
		this->qsize = qsize;
		buf = new int[qsize]; // 동적으로 배열 할당하는 법
		front = 0;
		rear = 0;
	}
	void Enqueue(int data)
	{
		if (IsFull() != 1)
		{
			rear = (rear + 1) % this->qsize;
			buf[rear] = data;
			cout << "front=" << front << " rear=" << rear << "  |  ";

			int temp = front;
			while (true)
			{
				if (front == rear)
					break;
				if (temp == rear)
					break;
				temp = (temp + 1) % this->qsize;
				cout << buf[temp] << "  |  ";
			}
			cout << endl;
		}
	}
	int Dequeue()
	{
		cout << "front=" << front << " rear=" << rear << "  |  ";
		for (int i = front + 1; i <= rear; i++)
			cout << buf[i] << "  |  ";
		cout << endl;
		front = (front + 1) % this->qsize;
		return buf[front];
	}
	int IsFull()
	{
		if ((rear + 1) % this->qsize == front)
		{
			cout << "큐가 꽉 찼음 \n";
			return 1;
		}
	}
	int IsEmpty()
	{
		if (front == rear)
		{
			cout << "큐가 비어있음\n";
			return 1;
		}
		else
			return 0;
	}
	int Get_Count()
	{
		return ((rear + 1) % this->qsize) - ((front + 1) % this->qsize);
	}
};

int main(void)
{
	int i;
	Queue q1;
	q1.InitQueue(5);
	for (i = 0; i < 4; i++)
	{
		q1.Enqueue(i);
	}
	cout << endl;

	while (!q1.IsEmpty())
		q1.Dequeue();
	cout << endl;

	for (i = 0; i < 5; i++)
	{
		q1.Enqueue(i);
	}
	cout << q1.Get_Count();
	return 0;
}