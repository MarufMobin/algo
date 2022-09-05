 void invert_tree( Node* node)
{
    if (node == NULL)
        return;
    else
    {
        Node* temp;


        mirror(node->leftChild);
        mirror(node->rightChild);

        temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;
    }
}

void inOrder( Node* node)
{
    if (node == NULL)
        return;
    inOrder(node->leftChild);
    cout << node->data << " ";
    inOrder(node->rightChild);
}