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

Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL) {
        if(temp -> data == 0) {
            zeroCount++;
        }
        else if (temp -> data == 1) {
            oneCount++;
        }
        else if (temp -> data == 2) {
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {
        if(zeroCount != 0) {
            temp -> data = 0;
            zeroCount--;
        }
        else if (oneCount != 0) {
            temp -> data = 1;
            oneCount--;
        }
        else if (twoCount != 0) {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
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
    // Create a linked list: 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> 1 -> 1 -> 2 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(2);
    cout << "This is original unsorted linked list" << endl;
    print(head);
    cout << endl;

    cout << "This Linked List is in sorted order. " << endl;
    sortList(head);
    print(head);

    return 0;
}