#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node* next;
    Node( int val )
    {
        value = val;
        next = NULL;
    }
};

// Set For The Value In Linked List
void inserAtTail( Node* &head, int val ){
    Node *newNode = new Node(val);
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    temp->next = newNode;

}

void display( Node *n ){
    while( n != NULL ){
        cout << n->value;
        if( n->next != NULL ) cout << " -> ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    inserAtTail( head, 1 );
    inserAtTail( head, 3 );
    display(head);
    return 0;
}
