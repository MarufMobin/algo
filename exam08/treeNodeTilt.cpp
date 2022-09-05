int Sum(Node* root,int &til)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=Sum(root->leftChild,til);
    int right=Sum(root->rightChild,til);
    
    til+=abs(left-right);
    
    return left+right+root->data;
}

int findTilt(Node* root)
{
    int tilt=0;
    Sum(root,tilt);
    return tilt;
}