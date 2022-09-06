#include "bt2.h"

int main(void)
{
    char command;
    BST bst;
    BTreeNode* temp = NULL;
    while (1) {
        element e;
        cout << "����(i), Ž��(s), ����Ʈ(p), ����(d), ������ȸ(l) : ";
        cin >> command;
        switch (command) {
        case 'i':
            cout << "�ܾ� : ";
            cin >> e.word;
            cout << "�ǹ� : ";
            cin >> e.meaning;
            bst.Insert(MakeBTreeNode(e));
            break;
        case 'd':
            cout << "�ܾ� : ";
            cin >> e.word;
            bst.Delete(e.word);
            break;
        case 'p':
            bst.Print();
            cout << endl;
            break;
        case 's':
            cout << "�ܾ� : ";
            cin >> e.word;
            temp = bst.Search(e.word);
            if (temp != NULL)
                cout << e.word << "�� �� : " << temp->key.meaning << endl;
            else
                cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
            break;
        case 'l':
            bst.Levelorder();
            break;
        case 'q':return 0;
        default:
            cout << "�߸� �Է½��ϴ�. ���Է��ϼ���" << endl;
        }
    }
    return 0;
}
