void zigzag_order(Node* root)
{
    if (!root)
        return;

    stack<struct Node*> currentLevel;
    stack<struct Node*> nextLevel;

    currentLevel.push(root);

    bool leftToright = true;
    while (!currentLevel.empty())
    {
        struct Node* temp = currentLevel.top();
        currentLevel.pop();

        if (temp)
        {

            cout << temp->data << " ";

            if (leftToright)
            {
                if (temp->leftChild)
                    nextLevel.push(temp->leftChild);
                if (temp->rightChild)
                    nextLevel.push(temp->rightChild);
            }
            else
            {
                if (temp->rightChild)
                    nextLevel.push(temp->rightChild);
                if (temp->leftChild)
                    nextLevel.push(temp->leftChild);
            }
        }

        if (currentLevel.empty())
        {
            leftToright = !leftToright;
            swap(currentLevel, nextLevel);
        }
    }
}