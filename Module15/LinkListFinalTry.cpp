#include<bits/stdc++.h>
using namespace std;
//Declare Node Class
class Node{
public:
    int value;
    Node* next;
    Node( int val ){
        value = val;
        next = NULL;
    }
};
//Insert Node Value In Tail
void inserAtTail( Node* &head, int val ){
    Node* newNode = new Node(val);
    if( head == NULL ) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Insert Node Value in Head
void inserAtHead( Node* &head, int val )
{
    //S1 : new Node Creation
        Node * newNode = new Node(val);
    //S2 : Update of newnode->Next
        newNode->next = head;
    //S3 : Update Head
        head = newNode;

}

//Display Output in All Node Value
void display( Node* val ){
    while( val != NULL ){
         cout << val->value;
         if( val->next != NULL ) cout << " -> ";
         val = val->next;
    }
}
int main(){
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
