#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(2);

//void HorseCout()
//{
//	arr.front() += 1;
//
//	if (arr.front() == arr.back())
//		return;
//
//	if (arr.front() % 2 != 0)
//		cout << arr.front() << endl;
//
//	return HorseCout();
//}

void NumCout(int a, int b)
{
	if (a == b)
		return;
	if (a % 2 != 0)
		cout << a << endl;
	
	return NumCout(++a, b);
}


void main(void) 
{
	int a, b = 0;
	cout << "���� ������ �� ���� �Է��Ͻÿ� : " << endl;
	cin >> a >> b;
	cout << endl;

	arr.front() = a;
	arr.back() = b;
	
	//HorseCout();
	NumCout(++a, b);
}