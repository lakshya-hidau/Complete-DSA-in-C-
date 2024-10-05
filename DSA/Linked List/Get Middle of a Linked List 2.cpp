#include <iostream>
using namespace std;

// Definition of the Node class
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

// Function to find the middle node of the linked list using two pointers
Node* getMiddle(Node* head) {
    if (head == NULL || head->next == NULL) { 
        return head;
    }

    if (head->next->next == NULL) {
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

// Wrapper function to find the middle node
Node* findMiddle(Node* head) {
    return getMiddle(head);
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete the linked list and free memory
void deleteList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Printing the linked list
    cout << "Linked List:" << endl;
    printList(head);

    // Finding and printing the middle node
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle Node Data: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // Clean up: deleting allocated memory
    deleteList(head);

    return 0;
}
