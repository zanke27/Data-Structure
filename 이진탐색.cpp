#include <iostream> 
#include <vector>
using namespace std;
vector<int>numbers;

void BinarySearch()
{
	string result;
	cout << "나이가 맞다면 YES, 많으면 UP, 적으면 DOWN을 입력하시오." << endl;

	int LEFT = 0, RIGHT = numbers.size() - 1;

	while (LEFT <= RIGHT)
	{
		int mid = (LEFT + RIGHT) / 2;
		cout << numbers[LEFT] << "  " << numbers[RIGHT] << endl;
		cout << numbers[mid] << "살 입니까? : ";
		cin >> result;
		if (result == "YES")
		{
			cout << "정답이다!";
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
	cout << "나이의 최소값, 최대값 입력: ";
	cin >> MIN >> MAX;
	for (int i = MIN; i <= MAX; i++)
		numbers.push_back(i);
	BinarySearch();
}