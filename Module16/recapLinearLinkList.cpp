#include<bits/stdc++.h>
using namespace std;
//void inserAtTail( Node *&head, int val );
//void inserAtHead( Node *&head, int val );
//void display( Node* val );
//int countLength( Node *&head );

//Declare Node Class
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
//All Function are here
void inserAtTail( Node *&head, int val );
void inserAtHead( Node *&head, int val );
void display( Node* val );
int countLength( Node *&head );
void insertionAtSpecificPossition( Node* &head, int pos, int value );


//Insert Node Value In Tail
void inserAtTail( Node *&head, int val )
{
    Node* newNode = new Node(val);
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

//Insert Node Value in Head
void inserAtHead( Node *&head, int val )
{
    //S1 : new Node Creation
    Node * newNode = new Node(val);
    //S2 : Update of newnode->Next
    newNode->next = head;
    //S3 : Update Head
    head = newNode;

}

//Display Output in All Node Value
void display( Node* val )
{
    while( val != NULL )
    {
        cout << val->value;
        if( val->next != NULL ) cout << " -> ";
        val = val->next;
    }
}

int countLength( Node *&head )
{
    int lengthList = 0;
    Node *temp = head;
    while( temp != NULL )
    {
        temp = temp->next;
        lengthList++;
    }
    return lengthList;
}

void insertionAtSpecificPossition( Node* &head, int pos, int value ){

    int i = 0;

    //S1 : Find the length of List
    Node* temp = head;

    // S2 : n-2 loop Traversing
    while( i < pos - 2 )
    {
        temp = temp->next;
        i++;
    }
    //S3 : Create New Node;
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node* head = NULL;
    // Choice 1 : insertion at Head
    // Choice 2 : insertion at Tail
    cout << "Choice 1: Insertion At Head " << endl;
    cout << "Choice 2: Insertion At Tail " << endl;
    cout << "Choice 3: Insertion At Specific Position " << endl;
    cout << "Choice 0: Terminate the Program " << endl;

    int n, pos;
    cout << endl << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while( choice != 0 )
    {
        switch(choice)
        {
        case 1:
            cout << "Enter the Value : ";
            cin >> n;
            inserAtHead(head, n);
            break;
        case 2:
            cout << "Enter the Value : ";
            cin >> n;
            inserAtTail( head, n);
            break;
        case 3:
            cout << "Enter the Desire Position : ";
            cin >> pos;
            cout << "Enter the Position Value : ";
            cin >> n;
            insertionAtSpecificPossition( head, pos, n );
        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
    }
    cout << endl << endl;
    display(head);
    cout << endl;
    cout << endl;
    int len = countLength(head);
    cout <<"length Of List " << len;
    return 0;
}

