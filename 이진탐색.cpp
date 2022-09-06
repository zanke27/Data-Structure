#include <iostream> 
#include <vector>
using namespace std;
vector<int>numbers;

void BinarySearch()
{
	string result;
	cout << "���̰� �´ٸ� YES, ������ UP, ������ DOWN�� �Է��Ͻÿ�." << endl;

	int LEFT = 0, RIGHT = numbers.size() - 1;

	while (LEFT <= RIGHT)
	{
		int mid = (LEFT + RIGHT) / 2;
		cout << numbers[LEFT] << "  " << numbers[RIGHT] << endl;
		cout << numbers[mid] << "�� �Դϱ�? : ";
		cin >> result;
		if (result == "YES")
		{
			cout << "�����̴�!";
			break;
		}
		else if (result == "UP")
		{
			LEFT = mid + 1;
		}
		else if (result == "DOWN")
		{
			RIGHT = mid - 1;
		}
	}
}

int main(void)
{
	int MIN, MAX;
	cout << "������ �ּҰ�, �ִ밪 �Է�: ";
	cin >> MIN >> MAX;
	for (int i = MIN; i <= MAX; i++)
		numbers.push_back(i);
	BinarySearch();
}