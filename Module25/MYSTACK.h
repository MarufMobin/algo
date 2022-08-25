#include <bits/stdc++.h>
using namespace std;
template <typename N>
class Node
{
public:
    N value;
    Node *next;
    Node *prev;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

// Stack  < float > st
template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    // Stack Constractor
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    // PUSH
    void push(S val)
    {

        Node<S> *newNode = new Node<S>(val);

        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    // POP
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        S check;
        // There is No Element in this Stack
        if (head == NULL)
        {
            cout << "Stack Underflow " << endl;
            return check;
        }
        if (top == head) // There is Only One Element
        {
            head = top = NULL;
        }
        else // There is More then One Element
        {
            top = delNode->prev;
            top->next = NULL;
        }
        check = delNode->value;
        delete delNode;
        count--;
        return check;
    }

    // EMPTY
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    // SIZE
    int size()
    {
        return count;
    }

    // TOP
    S Top()
    {
        S cheak;
        if (top == NULL)
        {
            cout << "Stack Underflow | There is no Element in Top " << endl;
        }
        else
        {
            cheak = top->value;
        }
        return cheak;
    }
};