#pragma once
#include <iostream>
#include <queue>
using namespace std;

struct element {
    string word;
    string meaning;
};

struct BTreeNode
{
    element key;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

BTreeNode* MakeBTreeNode(element e);

class BST {
    BTreeNode* root = NULL;
    void InsertRecur(BTreeNode* root, BTreeNode* node);
    void Delete(BTreeNode* parent, BTreeNode* node);
    void Print(BTreeNode* root);

public:
    void Insert(BTreeNode* node);
    void Delete(string word);
    void Print() { Print(root); };
    BTreeNode* Search(string word);
    void Levelorder();
};