#include <iostream>
using namespace std;

int main(void)
{
	int n = 0;
	int num = 0;
	int result = 0;
	int* arr;
	int low = 0;
	int high = 0;
	
	cin >> n;
	
	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
		
		if (i == 0) low = arr[i];
	
		if (low >= arr[i])
			low = arr[i];
		else if (high <= arr[i])
			high = arr[i];
	}

	result = high - low;

	cout << "높은거: " << high << endl;
	cout << "낮은거: " << low << endl;
	cout << "결과: " << result;
}