#include<iostream>
using namespace std;

class Stack
{
private:
	static const int STACK_MAX = 50;
	int top = -1;
	int data[STACK_MAX];
public:
	void Show()
	{
		if (top <= -1)
		{
			cout << "Stack is Empty" << endl;
			return;
		}
		for (int i = top; i > -1; i--)
			cout << "|" << data[i] << "|" << endl;
	}
	void Push(int _data)
	{
		top++;
		data[top] = _data;
		cout << "Push " << _data << endl;
	}
	void Pop()
	{
		if (top <= -1)
		{
			cout << "Stack is Empty" << endl;
			return;
		}
		cout << "delete " << data[top] << endl;
		data[top] = NULL;
		top--;
	}
};


int main(void)
{
	Stack s1;

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(1);
	s1.Show();
	s1.Pop();
	s1.Pop();
	s1.Show();
}