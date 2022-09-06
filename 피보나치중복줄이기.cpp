#include <iostream>
using namespace std;

int arr[1000] = { 0, };

int Fibonachi(int num)
{
	int result = 0;

	if (arr[num] != 0)
		return arr[num];

	if (num<=2)
	{
		return arr[num] = 1;
	}
	else
		return arr[num] = Fibonachi(num - 2) + Fibonachi(num - 1);
		
	return arr[num];
}

int main(void)
{
	int num = 0;
	cin >> num;
	cout << Fibonachi(num) << endl;

	//int arr[5] = { 0, };
	//cout << CheckMax(arr);


}