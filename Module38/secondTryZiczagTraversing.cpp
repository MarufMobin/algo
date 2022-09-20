#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode( int value ){
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};
void printTree(treeNode *root, int level);
void spacePrint(int level);
void inOrderTraversal(treeNode *root, string &chk); 
void preOrderTraversal(treeNode *root, string &chk) ;
void postOrderTraversal(treeNode *root, string &chk) ;
int levelOrderTraversal( treeNode* root, string &chk, int k );
int searchInorder( int inOrder[], int current, int start, int end );
treeNode* buildTreePreIn( int preOrder[], int inOrder[], int start , int end );
void printLeaves( treeNode* root);
void printLeftNonLeaves( treeNode* root );
void printRightNonLeaves( treeNode*root );
void boundaryTraversal( treeNode* root );


void inOrderTraversal(treeNode *root, string &chk) // Left Root Right 

{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->leftChild, chk);
    chk += (to_string(root->data) + " ");
    inOrderTraversal(root->rightChild, chk);
}

// PreOrder Traversal
void preOrderTraversal(treeNode *root, string &chk) // Root Left Right
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    preOrderTraversal(root->leftChild, chk);
    preOrderTraversal(root->rightChild, chk);
}

// Post Order Traversal
void postOrderTraversal(treeNode *root, string &chk) // Left Right  Root
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->leftChild, chk);
    postOrderTraversal(root->rightChild, chk);
    chk += to_string(root->data);
}

// Print Tree Class here
void printTree(treeNode *root, int level)
{
    if (root == NULL) // When the Tree Empty
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) // CASE 1
    {
        cout << root->data << endl;
        return;
    }
    else // Case 2
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

// Space Printer
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}

//Level Order Traversal 
int levelOrderTraversal( treeNode* root, string &chk, int k ){
        if( root == NULL ){
            return -1;
        }
        int level = 0;
        queue<treeNode*>q;
        q.push(root);
        q.push(NULL);

        int maxVal = -9999;
        while( !q.empty() ){
            treeNode* chkNode = q.front();
            q.pop();
            if( chkNode != NULL ){
                if( level == k ){
                    if( maxVal < chkNode->data ){
                        maxVal = chkNode->data;
                    }
                }
                cout << chkNode->data << " ";
                if( chkNode->leftChild != NULL ){
                    q.push( chkNode->leftChild );
                }
                if( chkNode->rightChild != NULL ){
                    q.push( chkNode->rightChild );
                }
            }
            else{
                if( !q.empty()){
                    q.push(NULL);
                    level++;
                }
            }
        }
    return maxVal;
}

int searchInorder( int inOrder[], int current, int start, int end ){
    for( int i = start; i < end; i++ ){
        if( inOrder[i] == current ){
            return i;
        }
    }
    return -1;
}

treeNode* buildTreePreIn( int preOrder[], int inOrder[], int start , int end ){

    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode* newNode = new treeNode(current);
    if( start == end ){
        return  newNode;
    }
    int pos = searchInorder( inOrder, current, start, end );
    newNode->leftChild = buildTreePreIn( preOrder, inOrder, start, pos-1 );
    newNode->rightChild = buildTreePreIn( preOrder, inOrder, pos+1, end );

    return newNode;
}

//Print Leaves Which is Print left and Right leaves
void printLeaves( treeNode* root)
{
    if( root == NULL ) return;
    if( root->leftChild == NULL && root->rightChild == NULL ){
        cout << root->data << " ";
        return;
    }
    printLeaves( root->leftChild );
    printLeaves( root->rightChild );
}

//Print Non Leaves left site
void printLeftNonLeaves( treeNode* root )
{
    if( root == NULL ) return;
    if( root->leftChild != NULL ){
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }else if( root->rightChild != NULL ){
        cout << root->data << " ";
        printLeftNonLeaves( root->rightChild );
    }
}

//Print Non Leaves Right Site 
void printRightNonLeaves( treeNode*root )
{
    if( root == NULL ) return;
     if( root->rightChild != NULL ){
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }else if( root->leftChild != NULL ){
        cout << root->data << " ";
        printLeftNonLeaves( root->leftChild );
    }
}


//Boundary Traversal 
void boundaryTraversal( treeNode* root ){
    if( root == NULL ) return;
    cout << root->data << " ";

    //Left Boundary Non-Leaves 
    printLeftNonLeaves( root->leftChild );
    // Left Boundary Leaves
    printLeaves( root->leftChild );
    // Right Boundary Leaves
    printLeaves( root->rightChild );
    // // Right Boundary Non-Leasvs
    printRightNonLeaves( root->rightChild );
}
treeNode* insertionBST( treeNode* root, int value ){
    
    treeNode* newNode = new treeNode(value);
    
    if( root == NULL ){
        root = newNode;
        return root;
    }
    // Value < root -> data 
    if( value < root->data ){
        root->leftChild = insertionBST( root->leftChild , value );
    }
    // Value > root -> data 
    else if ( value > root->data ){
        root->rightChild = insertionBST( root->rightChild, value );
    }
    return root;    
}
int main(){
    int n;
    cin >> n;
    treeNode *root = NULL;

    for( int i = 0; i < n; i++ ){
        int value;
        cin >> value;
        root = insertionBST( root, value );
    }
    string traversal = "";
    inOrderTraversal(root, traversal);
    cout << traversal << endl;
    return 0;
}
/* 
// Binary Search Tree 
input 
9
11 5 9 43 34 1 2 7 21 
1 2 5 7 9 11 21 34 43 ----> OUT PUT
*/