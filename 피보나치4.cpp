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
	srand(time(NULL)); // 현재시간을 이용한 난수 말들기
	int rnum = rand() % 10001;
	// 피보나치 돌린 합과 난수와 비교
	while (true)
	{
		fiboSum = Fibo(index); // 피보나치의 합을 구해서
		if (fiboSum < rnum)	   // 난수와 피보나치의 합을 판별
		{
			fiboMap[index] = fiboSum;
			index++;
		}
		else
			break;
	}
	// 배열의 가장 큰 수와 난수와 비교
	cout << "rnum : " << rnum << endl << endl;
	while (true)
	{
		for (int i = index; i > 0; i--)
		{
			if (rnum >= fiboMap[i])
			{
				rnum -= fiboMap[i];
				if (rnum == 0) // 뺀 값이 0이면
				{
					// 새 배열을 이용하여 만든 코드

					//for (int j = index; j > 0; j--)
					//{
					//	if (tempArr[j] != NULL)
					//		cout << "fibo[" << j << "] : " << tempArr[j] << endl;
					//}

					// 원래 배열을 이용하여 만든 코드
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