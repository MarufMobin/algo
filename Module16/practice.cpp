#include<bits/stdc++.h>
using namespace std;

//Define a Class
class Node{
public:
    int value;
    Node* next;
    Node( int val ){
       value = val;
       next = NULL;
    }
};
void insertIntoTail( Node* &head, int val ){
    Node* newNode = new Node(val);

    if( head == NULL )
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while( temp->next != NULL ){
       temp = temp->next;
    }
    temp->next = newNode;
}
void display( Node* n ){
    if( n == NULL ){
        cout << "Nothing To Show";
    }
    Node* temp = n;
    while( temp != NULL ){
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int main(){
    Node* head = NULL;
    insertIntoTail( head , 1 );
    insertIntoTail( head , 3 );
    insertIntoTail( head , 5 );
    insertIntoTail( head , 7 );
    insertIntoTail( head , 9 );
    display(head);
    return 0;
}
