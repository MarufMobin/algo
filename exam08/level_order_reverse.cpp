//Question NO : 03
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *leftChild;
    Node *rightChild;
    Node(int val)
    {
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

//Level Order Reverse Are here
void levelOrderReverse( Node* root ){
    if( root == NULL ){
        return;
    }
    queue<Node*>q;
    string reverse = "";
    q.push(root);
    q.push(NULL);
    string chk = "";

    while( q.size() ){
        Node *chkNode = q.front();
        q.pop();

        if( chkNode != NULL ){
            chk += to_string( chkNode->value );
            if( chkNode->leftChild != NULL ){
                q.push( chkNode->leftChild );
            }
            
            if( chkNode->rightChild != NULL ){
                q.push( chkNode->rightChild );
            }
        }
        else{
            reverse = chk+reverse;
            chk += " ";
            chk = "";
            if( !q.empty() ){
                q.push(NULL);
            }
        }
    }
    cout << reverse;
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

    string levelOrderTravers = "";

    levelOrderReverse(root);
    return 0;
}
 