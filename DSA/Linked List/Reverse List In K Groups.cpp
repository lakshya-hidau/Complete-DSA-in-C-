#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* kReverse(Node* head, int k) {
    // base case
    if (head == NULL) {
        return NULL;
    }

    // if our length is less than k so return as it is
    int len = 0;
    Node* check = head;
    while (check != NULL) {
        len++;
        check = check->next;
    }

    if (len < k) {
        return head;
    }

    // Step 1: Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 2: Recursive call
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // Step 3: Return head of reversed List
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    cout << "Original list: ";
    printList(head);

    head = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    // Clean up the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
