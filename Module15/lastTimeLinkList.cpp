#include<bits/stdc++.h>
using namespace std;
//Define a Class for Link List
class Node
{
public:
    int value;
    Node* next;
    Node( int val )
    {
        value = val;
        next = NULL;
    }
};
// Set Link List Tail Value
void inserAtTail( Node* &head, int val )
{
    Node *newNode = new Node(val);
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display( Node* n )
{
    while( n != NULL )
    {
        cout << n->value;
        if( n->next != NULL ) cout << " -> ";
        n = n->next;
    }
}
int main()
{
    Node* head = NULL;

    int n;
    char choice = 'y';
    while( choice == 'y' ){
        cout << "Enter the Value : ";
        cin >> n;
        inserAtTail(head, n);
        cout << "DO you Want to Continue (y/n) : ";
        cin >> choice;
    }
    display(head);
    return 0;
}

