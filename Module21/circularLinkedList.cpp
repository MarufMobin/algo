#include <bits/stdc++.h>
using namespace std;

// Declare Node Class
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

// Define Structure for Dynamic Array Define Perpuss
struct Test
{
    int position[1000];
};

// All Function are here
void inserAtTail(Node *&head, int val);
void inserAtHead(Node *&head, int val);
void display(Node *val);
int countLength(Node *&head);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpacificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int value);

// Insert Node Value In Tail
void inserAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}

// Insert Node Value in Head
void inserAtHead(Node *&head, int val)
{
    // S1 : new Node Creation
    Node *newNode = new Node(val);
    // S2 : Update of newnode->Next
    newNode->next = head;
    // S3: Update  the tail with new head
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // S4: Update of Head
    head = newNode;
}

// Display Output in All Node Value
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "The Link list is Empty";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->value;
        temp = temp->next;
        if( temp != head ) cout << " -> "; 
    } while (temp != head); 
}

int countLength(Node *&head)
{
    int lengthList = 0;
    Node *temp = head;

    do
    {
        temp = temp->next;
        lengthList++;
    } while (temp != head);
    return lengthList;
}

// Deletion At Head
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        //Delete Node 
        Node *delNode = temp;
        while( temp->next != head ){
            temp = temp->next;
        }
        temp->next = delNode->next;
        head = delNode->next;
        delete delNode;
    }
    else
    {
        cout << "There is no Value in the Linked List " << endl;
    }
}

// Deletion At Tail
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        // Head is Null
        if (temp == NULL)
            cout << "There is no Value in the Linked List " << endl;
        // Head is Tail
        else
            deletionAtHead(head);
    }
}

// Search By Value in link List Unique Position
int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int counter = 1;
    if (temp == NULL)
        return -1;
    while (temp->value != key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        counter++;
    }
    return counter;
}

// Deletion At Spacific Position
void deletionAtSpacificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            Node *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
    else
    {
        // Position Out Of Range
        if (position > countLength(head))
        {
            cout << "Position out of Bound ";
        }
        // Link List is Null
        else
            cout << "There is no value in the linked list " << endl;
    }
}

// Delete By Value Unique Linked List
void deletionByValueUnique(Node *&head, int value)
{
    // Find the Position of the Value
    int position;
    position = searchByValueUnique(head, value);
    // Delete the Node at that Position
    if (position == -1)
    {
        cout << "Value Not Found in the Linked List " << endl;
    }
    else
    {
        deletionAtSpacificPosition(head, position);
    }
}

int main()
{
    Node *head = NULL;
    cout << "Choice 1: Insertion At Head " << endl;
    cout << "Choice 2: Insertion At Tail " << endl;
    cout << "Choice 3: Deletion at Head " << endl;
    cout << "Choice 4: Insertion At Specific Position " << endl;
    cout << "Choice 5: Deletion at Tail " << endl;
    cout << "Choice 6: Deletion at Specific Position " << endl;
    cout << "Choice 0: Terminate the Program " << endl;
    cout << "Choice 00: Show The List Vlaue " << endl;

    int n, pos;
    cout << endl
         << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 00:
            cout << "Enter the Value : ";
            cin >> n;
            display(head);
            break;
        case 1:
            cout << "Enter the Value : ";
            cin >> n;
            inserAtHead(head, n);
            break;
        case 2:
            cout << "Enter the Value : ";
            cin >> n;
            inserAtTail(head, n);
            break;
        case 3:
            deletionAtHead(head);
            break;
        case 4:
            deletionAtTail(head);
            break;
        case 5:
            if (head == NULL)
            {
                cout << "There is No Value in the Link List " << endl;
                break;
            }
            cout << "Enter the Desire Position : ";
            cin >> pos;
            deletionAtSpacificPosition(head, pos);
            cout << endl;
            display(head);
            cout << endl;
            break;
        case 6:
            cout << "Enter the Value to Delete : ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
    }
    cout << endl
         << endl;
    display(head);
    cout << endl;
    cout << endl;
    int len = countLength(head);
    cout << "length Of List " << len;
    return 0;
}
