#include <iostream>
using namespace std;

/*************************************************
    Definition of class Node
**************************************************/
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node * removeDuplicates(Node *head)
{
    // empty list
    if(head == NULL) {
        return NULL;
    }

    // non-empty list
    Node* curr = head;
    while(curr != NULL) {

        // next node is dublicate node
        if(curr -> next != NULL && curr -> data == curr -> next -> data) {
            Node* next_next = curr -> next -> next;
            Node* NodeToDelete = curr -> next;
            delete (NodeToDelete);
            curr -> next = next_next;
        }
        // next node is different node
        else {
            curr = curr -> next;
        }
    }
    return head;
}

// tranvrese a linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    } cout << "NULL";
    cout << endl;
}

/******************************************************
    Main function to test the removeDuplicates function
*******************************************************/
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(5);
    cout << "This is original linked list" << endl;
    print(head);
    cout << endl;

    cout << "This Linked List has no Duplicate element ." << endl;
    removeDuplicates(head);
    print(head);
   

    return 0;
}