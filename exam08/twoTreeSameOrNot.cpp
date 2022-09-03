#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    return (p->value == q->value) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    int n;
    cin >> n;
    TreeNode* allNodesOne[n];
    

    for( int i = 0; i < n; i++ ){
        allNodesOne[i] = new TreeNode(-1);
    }

    for( int i = 0; i < n; i++ ){
        int value, left, right;
        cin >> value >> left >> right;
        if( left > n-1 || right > n-1 ){
            cout << "Invelid Index ";
            break;
        }
        if (left != -1)
        {
            allNodesOne[i]->left = allNodesOne[left];
        }

        if (right != -1)
        {
            allNodesOne[i]->right = allNodesOne[right];
        }
    }

    int m;
    cin >> m;
    TreeNode* allNodesTwo[m];
    //Second array 
    for( int i = 0; i < m; i++ ){
        allNodesTwo[i] = new TreeNode(-1);
    }

    for( int i = 0; i < m; i++ ){
        int value, left, right;
        cin >> value >> left >> right;
        if( left > m-1 || right > m-1 ){
            cout << "Invelid Index ";
            break;
        }
        if (left != -1)
        {
            allNodesTwo[i]->left = allNodesTwo[left];
        }

        if (right != -1)
        {
            allNodesTwo[i]->right = allNodesTwo[right];
        }
    }
    if( isSameTree( allNodesOne[0], allNodesTwo[0] ) ){
        cout << "These two binary trees are the same."<<endl;
    }else{
        cout << " These two binary trees are not the same " << endl;
    }
    return 0;
}