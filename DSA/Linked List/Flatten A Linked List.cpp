#include <iostream>
using namespace std;

class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge(Node* &down, Node* &rigth) {
    if (down == NULL) {
        return rigth;
    }
    if (rigth == NULL) {
        return down;
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (down != NULL && rigth != NULL) {
        if (down->data < rigth->data) {
            temp->child = down;
            temp = down;
            down = down->child;
        } else {
            temp->child = rigth;
            temp = rigth;
            rigth = rigth->child;
        }
    }

    while (down != NULL) {
        temp->child = down;
        temp = down;
        down = down->child;
    }

    while (rigth != NULL) {
        temp->child = rigth;
        temp = rigth;
        rigth = rigth->child;
    }

    Node* res = dummy->child;
    delete dummy; // Clean up dummy node
    return res;
}

Node* flattenLinkedList(Node* head) {
    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* down = head;
    Node* rigth = flattenLinkedList(head->next);
    down->next = NULL;

    Node* ans = merge(down, rigth);
    return ans;
}

// Utility function to print the flattened list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    // Create linked list nodes for testing
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    // Create child lists
    Node* c1 = new Node(7);
    Node* c2 = new Node(8);
    Node* c3 = new Node(9);
    
    n1->child = c1;
    n2->child = c2;
    n3->child = c3;

    // Create next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    // Flatten the linked list
    Node* flattenedList = flattenLinkedList(n1);

    // Print the flattened list
    cout << "Flattened linked list: ";
    printList(flattenedList);

    // Clean up memory (not implemented in this snippet)
    // It is important to free allocated memory to avoid memory leaks

    return 0;
}
