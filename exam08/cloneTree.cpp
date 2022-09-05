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
bool isSame(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2 && root1->data == root2->data)
        return isSame(root1->leftChild, root2->rightChild)
               && isSame(root1->rightChild, root2->leftChild);
    return false;
}

bool isSymmetric(struct Node* root)
{
    return isSame(root, root);
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

    if (isSymmetric(root))
        cout << "This tree is a symmetric tree";
    else
        cout << "This tree is not a symmetric tree";


    return 0;
}

/*
 User input style

    1 2 2
    3 4
    4 3
    -1 -1
    -1 -1
    -1 -1
    -1 -1

    1 2 2
    -1 3
    -1 3
    -1 -1
    -1 -1

*/
