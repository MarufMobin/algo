#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack
{
    Node *head;
    Node *top;
    int count = 0;

public:
   
    //Stack Constractor 
    Stack(){
        head = NULL;
        top = NULL;
    }
  
    // PUSH
    void push(int val)
    {

        Node *newNode = new Node(val);

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
    int pop()
    {
        Node *delNode;
        delNode = top;
        int check = -1;
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
    int Top()
    {
        int cheak;
        if (top == NULL)
        {
            cout << "Stack Underflow | There is no Element in Top " << endl;
            cheak = -1;
        }
        else
        {
            cheak = top->value;
        }
        return cheak;
    }

};
