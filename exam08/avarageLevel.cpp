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


void average_level(Node* root)
{
    vector<float> res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {


        int sum = 0, count = 0;
        queue<Node*> temp;
        while (!q.empty())
        {
            Node* n = q.front();
            q.pop();
            sum += n->data;
            count++;
            if (n->leftChild != NULL)
                temp.push(n->leftChild);
            if (n->rightChild != NULL)
                temp.push(n->rightChild);
        }
        q = temp;
        cout << (sum * 1.0 / count) << " ";
    }
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

    average_level(root);
    return 0;
}