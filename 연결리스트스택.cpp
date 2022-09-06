// push�� pop �Լ��� �����Ͻÿ� 
#include <iostream>
using namespace std;

typedef struct NODE {
    NODE* next;
    int data;
} NODE;

void Push(int _data);
int Pop();
bool isEmpty();
void printData();
void Menu();
NODE* s_top;

int main() {
    int data, nKey = 0;
    while (true) {
        Menu();
        cin >> nKey;
        cout << "\n";
        switch (nKey) {
        case 1:
            cout << "Push : ";
            cin >> data;
            Push(data);
            break;
        case 2:
            cout << "Pop : " << Pop() << endl;
            break;
        case 3:
            printData();
            break;
        default:
            cout << "�Է� ����" << endl;
            break;
        }
        cout << "\n";
    }
    return 0;
}

void Push(int _data) {
    // ������ ��� ���� ���� �ƴ� ���� �������
    NODE* p = new NODE;
    p->data = _data;
    if (isEmpty())
        p->next = NULL;
    else
        p->next = s_top;
    s_top = p;
}

int Pop() {
    // ���� �� ���� �ִ� ��带 �����ϰ� ����� ������ ���� ��ȯ���� 
    if (s_top == NULL)
        return -1;

    NODE* p = new NODE;
    p->data = s_top->data;
    s_top = s_top->next;
    
    if (s_top == NULL)
        return -1;

    return p->data;
}

void printData() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return;
    }
    NODE* top = s_top;
    for (; top != NULL; top = top->next) {
        cout << "| " << top->data << " |" << endl;
    }
    cout << "-----" << endl;
}

bool isEmpty() { return s_top == NULL; }

void Menu()
{
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Show Stack" << endl;
    cout << "INPUT : ";
}