#include <iostream>
using namespace std;
typedef struct linked {
    int data;
    struct linked* next; // �ڱ� ���� ������
}node;
node* head = NULL; // �ڷ��� ���� ��ġ
node* tail = NULL; // �ڷ��� ������ ��ġ
void Init();
void Insert(node* ptr);
void PrintList(node* ptr);
void Modify(node* ptr);
void InsertData(node* ptr);
void Delete(node* ptr);

int main() {
    int menu = 0;
    Init();
    while (1) {
        cout << "1. �Է� 2. ��� 3. ���� 4. ���� 5. ���� 6. ����" << endl;
        cout << "input menu : ";
        cin >> menu;
        switch (menu) {
        case 1:
            Insert(tail);
            break;
        case 2:
            PrintList(head);
            break;
        case 3:
            Modify(head);
            break;
        case 4:
            InsertData(head);
            break;
        case 5:
            Delete(head);
            break;
        case 6:
            break;
        default:
            cout << "select menu error.." << endl;
        }
        if (menu == 6) break;
    }
    return 0;
}
void Init() {
    head = new node;
    head->data = 0;
    head->next = NULL;
    tail = head; // �ʱ⿡�� tail�� head�� ���� ��ġ
    return;
}
void Insert(node* ptr) { // ����Ʈ�� �� ���� ���Ե�
    node* newnode = new node;
    int num = 0;
    cout << "input number : ";
    cin >> num;
    newnode->data = num; // newnode�� num ����
    newnode->next = NULL; // newnode�� �ڷ�� NULL�� ��
    ptr->next = newnode; // ptr next�� newnode�� �ٶ�
    tail = newnode;
    return;
}
void PrintList(node* ptr) {
    node* view = ptr->next; // head�� next�� view�� ����
    while (1) {
        cout << view->data << " -> "; // view�� ���� �ִ� �ڷ� ���
        view = view->next; // view�� ���� �� ����
        if (view == NULL) {
            cout << "NULL";
            break;
        }
    }
    cout << endl;
    return;
}
void Modify(node* ptr) { // �Է��� �ε����� ���� ������  
    int index = 0;
    int num = 0;
    int i;
    cout << "input modify index : ";
    cin >> index;
    cout << "input modify data :";
    cin >> num;
    for (i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    ptr->data = num;
    return;
}
void InsertData(node* ptr) { // �Է��� �ε��� �ڿ� ���Ե�
    node* newnode = new node;
    int index = 0, num = 0;
    int i;
    cout << "input InsertData index : "; // ��� ������ ���ΰ�?
    cin >> index;
    cout << "input data : "; // ��� ���� ������ ���ΰ�?
    cin >> num;
    for (i = 0; i < index; i++) // �Էµ� ��ġ ã��
        ptr = ptr->next;
    newnode->data = num; // newnode �ڷῡ ���� ����
    newnode->next = NULL; // newnode ������ NULL
    if (ptr->next == NULL) {
        ptr->next = newnode; // ptr�� ���� ��带 newnode�� ����
        tail = newnode; // tail�� newnode�� �̵�
    }
    else {
        newnode->next = newnode;
        newnode->data = num;
    }
    return;
}
void Delete(node* ptr) {
    node* temp = 0;
    int i;
    int index;
    if (head == tail) {
        cout << "not found data" << endl;
        return;
    }
    cout << "input delete index :";
    cin >> index;
    for (i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    temp = ptr->next;
    if (temp->next == NULL) {
        ptr->next = NULL;
        tail = ptr;
    }
    else {
        ptr->next = temp;
        tail = ptr;
    }
    delete(temp);
    return;
}