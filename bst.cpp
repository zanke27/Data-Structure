#include "bt.h"
#include <windows.h>

void BST::SetCursorPosition(int x, int y)
{
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(output, pos);
}

void BST::Print(BTreeNode* node, int x, int y)
{
    if (node == nullptr)
        return;

    SetCursorPosition(x, y);

    cout << node->data;
    Print(node->left, x - (5 / (y + 1)), y + 1);
    Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BST::Insert(BTreeNode* node) {//��� n�� ���� Ž�� Ʈ���� ������. ���� Ʈ���̸� n�� ��Ʈ�� �ϰ�, �׷��� ������ insertRecur�� ȣ���ؼ� ��带 ����
    if (root == NULL) root = node;
    else InsertRecur(root, node);
}

void BST::Delete(string word)
{
}

void BST::InsertRecur(BTreeNode* root, BTreeNode* node)
{
    if (GetData(node) == GetData(root))
        return;
    else if (GetData(node) < GetData(root)) {
        if (GetLeftSubTree(root) == NULL)
            MakeLeftSubTree(root, node);
        else
            InsertRecur(GetLeftSubTree(root), node);
    }
    else {
        if (GetRightSubTree(root) == NULL)
            MakeRightSubTree(root, node);
        else
            InsertRecur(GetRightSubTree(root), node);
    }
}

void BST::Delete(int key) {
    if (root == NULL) return;
    BTreeNode* parent = NULL; // ���� ����� �θ�
    BTreeNode* node = root; // ���ٳ��
    while (node != NULL && GetData(node) != key) {
        parent = node;
        node = (key < GetData(node)) ? GetLeftSubTree(node) : GetRightSubTree(node);
    }
    if (node == NULL) {//���� ��尡 Ʈ���� ����
        cout << "key is not in the tree" << endl;
        return;
    }
    else Delete(parent, node);
}

void BST::Delete(BTreeNode* parent, BTreeNode* node) {
    //1. �����Ϸ��� ��尡 �ܸ� ����� ���
    if (GetLeftSubTree(node) == NULL && GetRightSubTree(node) == NULL) {
        if (parent == NULL) // �����Ϸ��� ��尡 �ٳ���� ��
            root = NULL;
        else {
            if (GetLeftSubTree(parent) == node)
                MakeLeftSubTree(parent, NULL);
            else
                MakeRightSubTree(parent, NULL);
        }
    }
    //2. �����Ϸ��� ��尡 �ڽ� 1���� ���
    else if (GetLeftSubTree(node) == NULL || GetRightSubTree(node) == NULL) {
        //child�� ������ ����� ������ �ڽ�
        BTreeNode* child = (GetLeftSubTree(node) != NULL) ? GetLeftSubTree(node) : GetRightSubTree(node);
        //������ ��尡 ��Ʈ�̸� child�� ���ο� ��Ʈ�� ��
        if (node == root) root = child;
        //�ƴϸ� �θ����� �ڽ����� child�� ����
        else {
            if (GetLeftSubTree(parent) == node)
                MakeLeftSubTree(parent, child);
            else
                MakeRightSubTree(parent, child);
        }
    }
    //3. �����Ϸ��� ��尡 �ڽ� 2���� ���
    else {
        //�����Ϸ��� ����� ������ ����Ʈ������ ���� ���� ���(�İ� ���,succession)�� Ž��
        // s:�İ��� sp:�İ����� �θ���
        BTreeNode* sp = node;
        BTreeNode* s = GetRightSubTree(node);
        while (GetLeftSubTree(s) != NULL) {
            sp = s;
            s = GetLeftSubTree(s);
        }
        if (GetLeftSubTree(sp) == s)    // �İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
            MakeLeftSubTree(sp, GetRightSubTree(s));
        else // �İ� ��尡 ������ ����� �ٷ� ������ �ڽ��� ���
            MakeRightSubTree(sp, GetRightSubTree(s));
        //�İ� ��� ������ ������ ��忡 ����
        SetData(node, GetData(s));
        delete s;
    }
}

void BST::Print(BTreeNode* root)
{
}

int main() 
{
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();
    BTreeNode* bt5 = MakeBTreeNode();

    BST bst;
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    bst.Insert(bt3);
    bst.Insert(bt2);
    bst.Insert(bt1);
    bst.Insert(bt4);
    bst.Insert(bt5);
    bst.Delete(2);
    bst.Print(bst.root, 10, 0);
}