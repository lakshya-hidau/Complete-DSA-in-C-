#include <iostream>
using namespace std;

// Definition of the LinkedListNode class
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Recursive function to reverse the linked list
LinkedListNode<int>* revrese1(LinkedListNode<int> *head) {
    // Base case: if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Reverse the rest of the list
    LinkedListNode<int> *chotaHead = revrese1(head->next);

    // Make the next node point to the current node
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

// Wrapper function to reverse the linked list
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    return revrese1(head);
}

// Function to print the linked list
void printList(LinkedListNode<int> *head) {
    LinkedListNode<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete the linked list and free memory
void deleteList(LinkedListNode<int> *head) {
    LinkedListNode<int> *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    // Printing the original linked list
    cout << "Original Linked List:" << endl;
    printList(head);

    // Reversing the linked list
    head = reverseLinkedList(head);

    // Printing the reversed linked list
    cout << "Reversed Linked List:" << endl;
    printList(head);

    // Clean up: deleting allocated memory
    deleteList(head);

    return 0;
}
