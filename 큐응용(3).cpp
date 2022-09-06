#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

#define ODER_TERM 15 // ���� �ֹ� ����: �� ����

#define CHEEZE     0        // ���: ġ�ī��
#define MILK      1        // ���: ������ī��
#define CHOCO     2        // ���: ���ڸ�ī��

#define CHE_TERM    12       // �غ� �ð�(sec): ġ��
#define MILK_TERM    15       // �غ� �ð�(sec): ����
#define CHOCO_TERM    24       // �غ� �ð�(sec): ����

int main()
{
    int makeProc = 0; // ��ī�� ���� ���� ��Ȳ
    int cheOrder = 0, milkOrder = 0, chocoOrder = 0;
    int sec;

    queue<int> q;

    srand(time(NULL));

    for (sec = 0; sec < 3600; sec++) // 1�ð� ���� ����
    {
        if (sec % ODER_TERM == 0) // 15�� ���� �ֹ��� ����
        {
            switch (rand() % 3) // 3 �޴� �� ������ �ֹ���
            {
            case CHEEZE:
                if (makeProc == 0)
                {
                    cheOrder++;
                    makeProc = CHE_TERM;
                }
                else
                {
                    cheOrder++;
                    q.push(CHE_TERM);
                }
                break;

            case MILK:
                if (makeProc == 0)
                {
                    milkOrder++;
                    makeProc = MILK_TERM;
                }
                else
                {
                    milkOrder++;
                    q.push(MILK_TERM);
                }
                break;

            case CHOCO:
                if (makeProc == 0)
                {
                    chocoOrder++;
                    makeProc = CHOCO_TERM;
                }
                else
                {
                    chocoOrder++;
                    q.push(CHOCO_TERM);
                }
                break;
            }
        }

        makeProc--;

        if (makeProc == 0) {  // ���� �ϳ��� �� ������� ���� ��Ⱑ ���� ��
            if (q.empty() == false)
            {
                makeProc = q.front();
                q.pop();       // ����ٿ� �� ù��° ����� ����
            }
        }
    }

    cout << "Simulation Report!!" << endl;
    cout << "[Order Count]" << endl;
    cout << "- Cheese Makarong: " << cheOrder << endl;
    cout << "- Milk Makarong: " << milkOrder << endl;
    cout << "- Choco Makarong: " << chocoOrder << endl;
    cout << "�� Waiting room size: " << q.size() << endl;


    return 0;
}