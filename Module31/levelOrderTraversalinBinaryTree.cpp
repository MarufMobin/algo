#include <bits/stdc++.h>

using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};
// Show Print The Tree
void printTree(treeNode *root, int level);
// Space Printer also Base on Level
void spacePrint(int level);
// Inorder Traversal
void inOrder(treeNode *root, string &chk);

void inOrder(treeNode *root, string &chk) // Left Root Right 
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild, chk);
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}
// PreOrder Traversal
void preOrder(treeNode *root, string &chk) // Root Left Right
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
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

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invelid Index " << endl;
            break;
        }
        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    // printTree(allNodes[0], 0);
    string inOrderTraversalString = "";
    string preOrderTraversalString = "";
    string postOrderTraversalString = "";
    string levelordertraversal = "";

    // inOrder(allNodes[0], inOrderTraversalString);
    // cout << endl;
    // cout << "In Order Traversal: " <<  inOrderTraversalString << endl;


    // preOrder(allNodes[0], preOrderTraversalString);
    // cout << endl;
    // cout << "Pre Order Traversal: " <<  preOrderTraversalString << endl;


    // postOrder(allNodes[0], postOrderTraversalString);
    // cout << endl;
    // cout << "Post Order Traversal: " <<  postOrderTraversalString << endl;
    cout << "Level Order Traversal Are here : " ;
   int maxVal = levelOrderTraversal( allNodes[0], levelordertraversal, 2 );
   cout << "Max Value is : " << maxVal;
    return 0;
}

/*

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6


 */