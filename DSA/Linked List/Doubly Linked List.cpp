#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // destroctor
    ~Node() {
        int value = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free from node of data " << value << endl;
    }
};

// Get length of linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

// tranvrese a linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAthead(Node* &tail, Node* &head, int d) {

    // empty List
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else {
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    // insert at start
    if(position == 1) {
        insertAthead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    // insert at last position
    if(temp -> next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;    
}

void deleteNode(int position, Node* &head) {

    // deleteing first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }
    // deleteing any middle node or last node
    else {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr-> prev =  NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;     
    } 
}

int main()
{
    
    Node* head = NULL;
    Node* tail = NULL;

    //cout << getLength(node1) << endl;

    insertAthead(tail, head, 11);
    print(head);

    insertAthead(tail, head, 15);
    print(head);

    insertAthead(tail, head, 17);
    print(head);

    insertAtTail(tail, head, 10);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(tail, head, 1, 100);
    print(head);

    insertAtPosition(tail, head, 7, 102);
    print(head);

    deleteNode(7, head);
    print(head);
    cout << "Head " << head -> data << endl;
    cout << "Tail " << tail -> data << endl;
}