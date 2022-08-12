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
// Insert List in Head
void inserAtHead( Node* &head, int val )
{
    //S1 : new Node Creation
        Node * newNode = new Node(val);
    //S2 : Update of newnode->Next
        newNode->next = head;
    //S3 : Update Head
        head = newNode;

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
    // Choice 1 : insertion at Head
    // Choice 2 : insertion at Tail
    cout << "Choice 1: Insertion At Head " << endl;
    cout << "Choice 2: Insertion At Tail " << endl;
    cout << "Choice 3: Terminate the Program " << endl;

    int n;
    int choice = 2;
    while( choice == 1 || choice == 2 ){
        cout << "Enter the Value : ";
        cin >> n;
        if( choice == 1 ) inserAtHead(head, n);
        else if( choice == 2 ) inserAtTail( head, n);
        cout << "Next Choice : ";
        cin >> choice;
    }
    display(head);
    return 0;
}

