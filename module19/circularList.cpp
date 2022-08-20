#include<bits/stdc++.h>
using namespace std;

class doublyNode{
public:
    int val;
    doublyNode* prev;
    doublyNode* next;
    doublyNode( int val ){
        this->val = val;
        prev = NULL;
        next = NULL; 
    }
};

//Insertion at tail Function
void insertionAtTail( doublyNode* &head, int value ){
    doublyNode *newNode = new doublyNode(value);
    if( head == NULL ){
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

//Insertion at Head function
void insertionAtHead( doublyNode* &head, int value ){
    //S1: New Node Creation 
    doublyNode *newNode = new doublyNode(value);
    //S2: UPdate of head->prev
    head->prev = head;
    //S3: Update of newNode->next
    newNode->next = head;
    //S4: Update of head
    head = newNode;
}

//Display Doubly Linked List
void display( doublyNode* n ){
    while ( n != NULL )
    {
        cout << n->val;
        if( n->next != NULL ) cout << "----> ";
        n = n->next;
    }
    cout << endl << endl;
}

//Cout The Lenght Of Linked List
int countLength(doublyNode* &head){
    int count = 0;
    doublyNode *temp = head;
    while( temp != NULL ){
        count++;
        temp = temp->next;
    }
    return count;
}

//Reverse Linked List Print 
void displayReverse( doublyNode* &head ){
    doublyNode* temp = head;
    while ( temp->next != NULL )
    {
        temp = temp->next;
    }
    while( temp != NULL ){
        cout << temp->val;
        if(temp->prev != NULL )
            cout << " ---> ";
            temp = temp->prev;
    }
    cout << endl << endl;    
}
int main(){
    doublyNode * head = NULL;
    int value , position;
    
    cout << "Choice 1: Insertion at Head " << endl;
    cout << "Choice 2: Insertion at Tail " << endl;
    cout << "Choice 3: Reverse Print " << endl;
    cout << "Choice 0: Exit " << endl;
    cout << endl;
    cout << "Next Choice : ";
    int choice;
    cin >> choice;

    while( choice != 0 ){
        switch( choice ){
            case 1:
                cout << "Enter the Value : ";
                cin >> value;
                insertionAtHead(head, value );
                break;
            case 2:
                cout << "Enter the Value : ";
                cin >> value;
                insertionAtTail( head, value );
                break;
            case 3:
                displayReverse(head);
                break;
           default:
                break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl <<  "Doubly Linked List: ";
    display(head);
    cout << "Length of the Doubly Linked List: " << countLength(head) << endl;

    return 0;
}