#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int  data;
    Node* leftChild;
    Node* rightChild;

    Node(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};


bool isUnivalTree(Node* root)
{
    if (!root)
    {
        return true;
    }
    if (root->leftChild != NULL
            && root->data != root->leftChild->data)
        return false;

    if (root->rightChild != NULL
            && root->data != root->rightChild->data)
        return false;

    return isUnivalTree(root->leftChild)
           && isUnivalTree(root->rightChild);
}

int main()
{
    int a;
    cin>>a;
    Node * root = new Node(a);

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node* presentRoot = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node * n1 = NULL;
        Node * n2 = NULL;
        if(x != -1) n1 = new Node(x);
        if(y != -1) n2 = new Node(y);
        presentRoot->leftChild = n1;
        presentRoot->rightChild = n2;

        if(n1 != NULL) q.push(n1);
        if(n2 != NULL) q.push(n2);
    }

    if (isUnivalTree(root) == 1)
    {
        cout << "This is an uni-valued tree.";
    }
    else
    {
        cout << "This is not an uni-valued tree.";
    }
    return 0;
}
