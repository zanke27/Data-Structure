#include "bt2.h"

int main(void)
{
    char command;
    BST bst;
    BTreeNode* temp = NULL;
    while (1) {
        element e;
        cout << "삽입(i), 탐색(s), 프린트(p), 삭제(d), 레벨순회(l) : ";
        cin >> command;
        switch (command) {
        case 'i':
            cout << "단어 : ";
            cin >> e.word;
            cout << "의미 : ";
            cin >> e.meaning;
            bst.Insert(MakeBTreeNode(e));
            break;
        case 'd':
            cout << "단어 : ";
            cin >> e.word;
            bst.Delete(e.word);
            break;
        case 'p':
            bst.Print();
            cout << endl;
            break;
        case 's':
            cout << "단어 : ";
            cin >> e.word;
            temp = bst.Search(e.word);
            if (temp != NULL)
                cout << e.word << "의 뜻 : " << temp->key.meaning << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;
            break;
        case 'l':
            bst.Levelorder();
            break;
        case 'q':return 0;
        default:
            cout << "잘못 입력습니다. 재입력하세요" << endl;
        }
    }
    return 0;
}
