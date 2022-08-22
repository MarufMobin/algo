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

public:
    // PUSH
    void push( int val ){
        
        Node* newNode = new Node( val );

        if( head == NULL ){
            head = top = newNode;
            return;
        }
        
        top->next = newNode;
        newNode->prev = top;    
        top = newNode;

    }
    // POP
    // EMPTY
    // SIZE
    // TOP
};

int main()
{
}