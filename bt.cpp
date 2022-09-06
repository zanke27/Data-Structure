#include "bt.h"

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode * nd = new BTreeNode; //make binary tree
    nd->left = NULL; //initialize
    nd->right = NULL; //initialize
    return nd; //return pointer
}

void DeleteBTreeNode(BTreeNode* bt) {
    delete bt;
}

int GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, int data) {
    bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    // if there is a node in left link, delete it
    if (main->left != NULL) delete main->left;
    // put sub in left link of main
    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    // if there is a node in right link, delete it
    if (main->right != NULL) delete main->right;
    // put sub in right link of main
    main->right = sub;
}

void PreorderTraverse(BTreeNode* bt)
{
    // 구현해보자!
    if (bt == NULL) return; 

    cout << bt->data << " ";
    if (bt->left != NULL)
        PreorderTraverse(bt->left);
    if (bt->right != NULL)
        PreorderTraverse(bt->right);
}
void InorderTraverse(BTreeNode* bt)
{
    // 구현해보자!
    if (bt == NULL) return;

    if (bt->left != NULL)
        InorderTraverse(bt->left);
    cout << bt->data << " ";
    if (bt->right != NULL)
        InorderTraverse(bt->right);
}
void PostorderTraverse(BTreeNode* bt)
{
    // 구현해보자!
    if (bt == NULL) return;

    if (bt->left != NULL)
        PostorderTraverse(bt->left);
    if (bt->right != NULL)
        PostorderTraverse(bt->right);
    cout << bt->data << " ";
}

BTreeNode* MakeExpTree(string exp)
{
    stack<BTreeNode*> stack;
    BTreeNode* pnode;
    for (int i = 0; i < exp.length(); i++)
    {
        pnode = MakeBTreeNode();
        if (isdigit(exp[i]))
        {
            SetData(pnode, exp[i] - '0');
        }
        else
        {
            SetData(pnode, exp[i]);
            MakeRightSubTree(pnode, stack.top());
            stack.pop();
            MakeLeftSubTree(pnode, stack.top());
            stack.pop();
        }
        stack.push(pnode);
    }
    pnode = stack.top();
    stack.pop();
    return pnode;
}

int EvaluateExpTree(BTreeNode* bt)
{
    int op1, op2;
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
    {
        return bt->data;
    }
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    switch (GetData(bt))
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
    return 0;
}

int prec(char op) {
    // 구현해보자!
    if (op == '*' || op == '/') return 1;
    else if (op == '+' || op == '-') return 2;
}
string infixToPostfix(string infix) {
    stack<char> huwiStack;
    stack<char> yunsanStack;

    string temp = "";

    int count = 0;

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] - '0' > 0 && infix[i] - '0' < 10)
            cout << infix[i];
        else if (yunsanStack.empty())
            yunsanStack.push(infix[i]);
        else if (!yunsanStack.empty())
        {
            if (yunsanStack.top() == '/' || yunsanStack.top() == '*')
            {
                cout << yunsanStack.top();
                yunsanStack.pop();
                yunsanStack.push(infix[i]);
            }
            else if (yunsanStack.top() == '+' || yunsanStack.top() == '-')
            {
                if (infix[i] == '/' || infix[i] == '*')
                    yunsanStack.push(infix[i]);
                else if (infix[i] == '+' || infix[i] == '-')
                {
                    cout << yunsanStack.top();
                    yunsanStack.pop();
                    yunsanStack.push(infix[i]);
                }
            }
        }
        count++;
    }

    while (true)
    {
        if (!yunsanStack.empty())
        {
            temp += yunsanStack.top();
            yunsanStack.pop();
        }
        else
        {
            break;
        }
    }
    return temp;
}