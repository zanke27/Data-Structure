#include <iostream>
using namespace std;

// 1차원 배열을 이용하여 주민등록번호 입력받기
// 성별을 판별하기
// 출생 연도 출력
// 나이 출력하기

void YearDay(char array[])
{
	cout << "출생 연도는 ";
	for (int i = 0; i < 2; i++)
		cout << array[i];
	cout << "년 ";
	for (int i = 2; i < 4; i++)
		cout << array[i];
	cout << "월 ";
	for (int i = 4; i < 6; i++)
		cout << array[i];
	cout << "일 입니다.";
}

int main(void)
{
	char array[14];
	int age = 0;
	int nums[14] = {};
	int testNum = 0;
	int areaNum = 0;
	int number = 2;

	cout << "주민등록번호 입력 : ";
	cin >> array;
	for (int i = 0; i < 13; i++)
	{
		nums[i] = array[i] - '0';
	}

	cout << endl;

	// char로 받아왔기 때문에 48을 빼서 구하기
	if (((nums[6]) % 2) == 0)
		cout << "성별은 여자" << endl;
	else
		cout << "성별은 남자" << endl;

	if (nums[6] < 3)
		age += 1900;
	else
		age += 2000;
	age += (nums[0]) * 10;
	age += nums[1];
	age = 2022 - age;

	YearDay(array);

	cout << "나이는 " << age << endl << endl;

	// 출신지역 출력하기
	areaNum += nums[7] * 10;
	areaNum += nums[8];
	if (areaNum >= 8) cout << "출신 지역은 서울입니다." << endl;
	else if (areaNum >= 12) cout << "출신 지역은 부산입니다." << endl;
	else if (areaNum >= 15) cout << "출신 지역은 인천입니다." << endl;

	// 유효성 검사

	int m = 0;

	for (int i = 0; i < 12; i++)
	{
		nums[i] *= number;
		testNum += nums[i];
		number++;
		if (number >= 10)
			number = 2;
	}

	m = (11 - ((testNum) % 11)) % 10;
	if (m == nums[12]) cout << "유효성 검사 통과";
	else cout << "유효성 검사 실패" << endl;
}