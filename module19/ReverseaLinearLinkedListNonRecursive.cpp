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
void insertionAtSpecificPossition(Node *&head, int pos, int value);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchValue, int n);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpacificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int value);
Node *reverseNonRecursive(Node *&head);

// Insert Node Value In Tail
void inserAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert Node Value in Head
void inserAtHead(Node *&head, int val)
{
    // S1 : new Node Creation
    Node *newNode = new Node(val);
    // S2 : Update of newnode->Next
    newNode->next = head;
    // S3 : Update Head
    head = newNode;
}

// Display Output in All Node Value
void display(Node *val)
{
    while (val != NULL)
    {
        cout << val->value;
        if (val->next != NULL)
            cout << " -> ";
        val = val->next;
    }
}

int countLength(Node *&head)
{
    int lengthList = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        lengthList++;
    }
    return lengthList;
}

// Insert A Value in Specific Position in Link list
void insertionAtSpecificPossition(Node *&head, int pos, int value)
{

    int i = 0;

    // S1 : Find the length of List
    Node *temp = head;

    // S2 : n-2 loop Traversing
    while (i < pos - 2)
    {
        temp = temp->next;
        i++;
    }
    // S3 : Create New Node;
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
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

// Search By Value in Link list Which is Duplication Places
void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->next;
        count++;
    }
    cout << endl;
    if (flag == 0)
        cout << " The Search Value is not yet in the List " << endl;
    else
    {
        position[0] = k;
        cout << " The Value is Found At Position : ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << " , ";
        }
        cout << endl;
    }
}

// Search by Duplicate Value Return type Structure
Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
}

// Search By Value Unique Search where are Stay my Value
void searchByValueUnique(Node *&head, int searchValue, int n)
{
    // Step 1: Search the Position of  the Search Value
    int position;
    position = searchByValueUnique(head, searchValue);
    // Step 2: Insert the Value at the Position + 1
    insertionAtSpecificPossition(head, position + 1, n);
}

// Deletion At Head
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->next;
        delete temp;
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

// Reverse Linked List Non Recursive Way
Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return head;
    }
    Node *next = head->next;

    while (true)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (current == NULL)
        {
            break;
        }
        next = next->next;
    }
    return prev;
}

//Reverse Recursive Way 
Node *reverseRecursive(Node* &head ){
    // Base Call 
    if( head == NULL ||  head->next == NULL ) {
        if( head == NULL ) cout << "The Linked List is Empty" << endl;
        return head;
    }
    //Recursive Call
    Node* newHead = reverseRecursive( head->next );
    newHead->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;
    cout << "Choice 1: Dispaly The Listing " << endl;
    cout << "Choice 2: Insertion At Head " << endl;
    cout << "Choice 2: Insertion At Tail " << endl;
    cout << "Choice 3: Insertion At Specific Position " << endl;
    cout << "Choice 4: Search a Value(Unique List) " << endl;
    cout << "Choice 5: Search a Value(Duplication enable List) " << endl;
    cout << "Choice 6: Insertion After a Specific Value( Unique List ) " << endl;
    cout << "Choice 7: Deletion at Head " << endl;
    cout << "Choice 8: Deletion at Tail " << endl;
    cout << "Choice 9: Deletion at Specific Position " << endl;
    cout << "Choice 10: Deletion By Value ( Unique List ) " << endl;
    cout << "Choice 11: Reversal of List Non-Recursive" << endl;
    cout << "Choice 12: Reversal of List Recursive Way" << endl;
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
            cout << "Enter the Desire Position : ";
            cin >> pos;
            cout << "Enter the Position Value : ";
            cin >> n;
            insertionAtSpecificPossition(head, pos, n);
            break;
        case 4:
            cout << "Enter the Value to Search : ";
            cin >> n;
            pos = searchByValueUnique(head, n);
            if (pos != -1)
            {
                cout << "The Number is at Position " << pos << endl;
            }
            else
            {
                cout << "The number is not Yet";
            }
            break;
        case 5:
            cout << "Enter the Value to Search : ";
            cin >> n;
            // searchByValueDuplicate(head, n);
            Test T;
            T = searchByValueDuplicateReturn(head, n);
            if (T.position[0] == 1)
            {
                cout << "The Search Value in not yet in this " << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The Value is Found at Position : ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << " , ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter The Value : To Search : ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the Value To Insert : ";
            cin >> n;
            searchByValueUnique(head, searchValue, n);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
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
        case 10:
            cout << "Enter the Value to Delete : ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        case 11:
           head = reverseNonRecursive(head);
            break;
        case 12:
            head = reverseRecursive(head);
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
