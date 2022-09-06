#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int fiboSum = 0;
int fiboMap[10000] = { 0, };
int Fibo(int n)
{
	if (fiboMap[n] > 0)
		return fiboMap[n];
	else
		return (fiboMap[n] = Fibo(n - 1) + Fibo(n - 2));
}

int main(void)
{
	bool isEnd = false;
	int index = 2;
	int tempArr[50] = { 0, };
	fiboMap[1] = fiboMap[2] = 1;
	srand(time(NULL)); // ����ð��� �̿��� ���� �����
	int rnum = rand() % 10001;
	// �Ǻ���ġ ���� �հ� ������ ��
	while (true)
	{
		fiboSum = Fibo(index); // �Ǻ���ġ�� ���� ���ؼ�
		if (fiboSum < rnum)	   // ������ �Ǻ���ġ�� ���� �Ǻ�
		{
			fiboMap[index] = fiboSum;
			index++;
		}
		else
			break;
	}
	// �迭�� ���� ū ���� ������ ��
	cout << "rnum : " << rnum << endl << endl;
	while (true)
	{
		for (int i = index; i > 0; i--)
		{
			if (rnum >= fiboMap[i])
			{
				rnum -= fiboMap[i];
				if (rnum == 0) // �� ���� 0�̸�
				{
					// �� �迭�� �̿��Ͽ� ���� �ڵ�

					//for (int j = index; j > 0; j--)
					//{
					//	if (tempArr[j] != NULL)
					//		cout << "fibo[" << j << "] : " << tempArr[j] << endl;
					//}

					// ���� �迭�� �̿��Ͽ� ���� �ڵ�
					for (int j = index; j > 0; j--)
					{
						if (fiboMap[j] != 0)
							cout << "fibo[" << j << "] : " << fiboMap[j] << endl;
					}
					isEnd = true;
				}
			}
			else
			{
				fiboMap[i] = 0;
			}
		}
		if (isEnd)
			break;
		else
		{
			cout << "-1";
			break;
		}
	}
}