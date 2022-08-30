#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int value;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode( int val ){
        this->value = val;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

//Print Tree All Nodes here
void printTree( treeNode* root, int level );
void spacePrint( int level );
void inOrder( treeNode* root, string &chk );
void preOrder( treeNode* root, string &chk );
void postOrder( treeNode* root, string &chk );

// Print Tree Hayararchy are here
void printTree( treeNode* root, int level ){
    if( root == NULL ) return;

    if( root->leftChild == NULL && root->rightChild == NULL ){
        cout << root->value << endl;
        return;
    }else{
        cout << endl;
        spacePrint( level );
        cout << "Root : " << root->value << endl;
    }

    if( root->leftChild != NULL ){
        spacePrint( level );
        cout << "Left: ";
        printTree( root->leftChild, level+1 );
    }

    if( root->rightChild != NULL ){
        spacePrint( level );
        cout << "Right: ";
        printTree( root->rightChild, level+1 );
    }
}

// Space Print here
void spacePrint( int level ){
    for( int i = 0; i < level; i++ ){
        cout << "   ";
    }
}

//In Order traversal
void inOrder( treeNode* root, string &chk ){
    if( root == NULL ) return;
    inOrder( root->leftChild, chk );
    chk += to_string( root->value );
    inOrder( root->rightChild, chk );
}

//Pre Order Traversal
void preOrder( treeNode* root, string &chk ){
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->value);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}

// Post Order Traversal
void postOrder(treeNode *root, string &chk) // Left Right  Root
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->value);
}

int main(){
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for( int i = 0; i < n; i++ ){
       allNodes[i] = new treeNode(-1);
    }

    for( int i = 0; i < n; i++ ){
        int data, left, right;
        cin >> data >> left >> right;
        allNodes[i]->value = data;

        if( left > n-1 || right > n-1 ){
            cout << "Invelid Index "<< endl;
            break;
        }

        if( left != -1 ){
            allNodes[i]->leftChild = allNodes[left];
        }

        if( right != -1 ){
            allNodes[i]->rightChild = allNodes[right];
        }

    }
    printTree( allNodes[0], 0);
    
    string inOrderTraversalString = "";
    string preOrderTraversalString = "";
    string postOrderTraversalString = "";

    inOrder(allNodes[0], inOrderTraversalString);
    cout << endl;
    cout << "In Order Traversal: " <<  inOrderTraversalString << endl;


    preOrder(allNodes[0], preOrderTraversalString);
    cout << endl;
    cout << "Pre Order Traversal: " <<  preOrderTraversalString << endl;


    postOrder(allNodes[0], postOrderTraversalString);
    cout << endl;
    cout << "Post Order Traversal: " <<  postOrderTraversalString << endl;
    return 0;
}