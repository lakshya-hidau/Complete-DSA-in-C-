#include <iostream>
using namespace std;

// Definition of LinkedListNode class
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

// Function to reverse a linked list
template <typename T>
LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    LinkedListNode<T> *prev = NULL;
    LinkedListNode<T> *curr = head;
    LinkedListNode<T> *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    // Printing original linked list
    cout << "Original Linked List:" << endl;
    LinkedListNode<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Reversing the linked list
    head = reverseLinkedList(head);

    // Printing reversed linked list
    cout << "Reversed Linked List:" << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Clean up: deleting allocated memory
    temp = head;
    while (temp != NULL)
    {
        LinkedListNode<int> *next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}
