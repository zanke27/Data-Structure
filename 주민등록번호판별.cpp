#include <iostream>
using namespace std;

// 1���� �迭�� �̿��Ͽ� �ֹε�Ϲ�ȣ �Է¹ޱ�
// ������ �Ǻ��ϱ�
// ��� ���� ���
// ���� ����ϱ�

void YearDay(char array[])
{
	cout << "��� ������ ";
	for (int i = 0; i < 2; i++)
		cout << array[i];
	cout << "�� ";
	for (int i = 2; i < 4; i++)
		cout << array[i];
	cout << "�� ";
	for (int i = 4; i < 6; i++)
		cout << array[i];
	cout << "�� �Դϴ�.";
}

int main(void)
{
	char array[14];
	int age = 0;
	int nums[14] = {};
	int testNum = 0;
	int areaNum = 0;
	int number = 2;

	cout << "�ֹε�Ϲ�ȣ �Է� : ";
	cin >> array;
	for (int i = 0; i < 13; i++)
	{
		nums[i] = array[i] - '0';
	}

	cout << endl;

	// char�� �޾ƿԱ� ������ 48�� ���� ���ϱ�
	if (((nums[6]) % 2) == 0)
		cout << "������ ����" << endl;
	else
		cout << "������ ����" << endl;

	if (nums[6] < 3)
		age += 1900;
	else
		age += 2000;
	age += (nums[0]) * 10;
	age += nums[1];
	age = 2022 - age;

	YearDay(array);

	cout << "���̴� " << age << endl << endl;

	// ������� ����ϱ�
	areaNum += nums[7] * 10;
	areaNum += nums[8];
	if (areaNum >= 8) cout << "��� ������ �����Դϴ�." << endl;
	else if (areaNum >= 12) cout << "��� ������ �λ��Դϴ�." << endl;
	else if (areaNum >= 15) cout << "��� ������ ��õ�Դϴ�." << endl;

	// ��ȿ�� �˻�

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
	if (m == nums[12]) cout << "��ȿ�� �˻� ���";
	else cout << "��ȿ�� �˻� ����" << endl;
}