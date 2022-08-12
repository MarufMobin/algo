#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    //Constractor Create
    Node( int val )
    {
        value = val;
        Next = NULL;
    }
};

void insertAtTail( Node* &head, int val )
{
    Node *newNode = new Node(val);
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while( temp->Next != NULL )
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void display( Node *n )
{
    while( n != NULL )
    {
        cout << n->value;
        if( n->Next != NULL ) cout << " -> ";
        n = n->Next;
    }
}
int main()
{

    Node* head = NULL;
//    Node* head = new Node();
//    Node* second = new Node();
//    Node* third = new Node();
//    Node* fourth = new Node();
    insertAtTail( head, 1 );
    insertAtTail( head, 2 );
    insertAtTail( head, 5 );
//    head->value = 1;
//    second->value = 5;
//    third->value = 8;
//    fourth->value = 9;

//    head->Next = second;
//    second->Next = third;
//    third->Next = fourth;
//    fourth->Next = NULL;

    display(head);

    return 0;
}
