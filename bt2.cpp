#include "bt2.h"

BTreeNode* BST::Search(string word)
{
    BTreeNode* p = root;
    while (p != NULL) {
        if (word == p->key.word)
            return p;
        else if (word[0] < p->key.word[0])
            p = p->left;
        else if (word[0] > p->key.word[0])
            p = p->right;
    }
    return p;     // 탐색에 실패했을 경우 NULL 반환
}

void BST::InsertRecur(BTreeNode* root, BTreeNode* node)
{
    if (root == NULL)
        BST::root = node;
    else
    {
         
    }
}

void BST::Insert(BTreeNode* node)
{
    InsertRecur(root, node);
}

void BST::Delete(BTreeNode* parent, BTreeNode* node)
{

}

void BST::Delete(string word)
{

}

void BST::Print(BTreeNode* root)
{
    queue<BTreeNode*> q;
    BTreeNode* currentNode = root;
    while (currentNode)
    {
        cout << currentNode->key.word << " " << currentNode->key.meaning << endl;
        if (currentNode->left != NULL) q.push(currentNode);
        if (currentNode->right != NULL) q.push(currentNode);
        if (q.empty()) return;
        currentNode = q.front();
        q.pop();
    }
}

void BST::Levelorder()
{
    //queue<BTreeNode*> q;
    //BTreeNode* currentNode = root;
    //while (currentNode)
    //{
    //    //cout << currentNode->key.word << endl;
    //    if (currentNode->left != NULL) q.push(currentNode);
    //    if (currentNode->right != NULL) q.push(currentNode);
    //    if (q.empty()) return;
    //    currentNode = q.front();
    //    q.pop();
    //}
}

BTreeNode* MakeBTreeNode(element e)
{
    return nullptr;
}
