#include <iostream>
using namespace std;

int topIndex = 0;
const int SIZE = 5;
char stackArr[SIZE] = { NULL, };
string stackName = "";

void Fresh(string name)
{
	stackName = name;
	cout << "Construcing stack " << stackName << endl;
	topIndex = -1;
}

void Push(char in)
{
	if (topIndex == SIZE-1)
	{
		cout << "Stack " << stackName << " is full" << endl;
		return;
	}

	topIndex++;
	cout << "Stack[" << topIndex << "] : " << in << endl;
	stackArr[topIndex] = in;
}

char Pop()
{
	if (topIndex == -1)
	{
		cout << "Stack " << stackName << " is empty" << endl;
		return 0;
	}

	return stackArr[topIndex--] ;
}

int main(void)
{
	Fresh("A");
	
	Push('a');
	Push('b');
	Push('c');
	Push('d');
	Push('e');
	Push('e');

	cout << Pop() << endl;
	cout << Pop() << endl;
	cout << Pop() << endl;
	cout << Pop() << endl;
	cout << Pop() << endl;
	cout << Pop() << endl;
}