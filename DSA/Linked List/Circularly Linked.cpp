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

/*************************************************
    Function to check if the linked list is circular
**************************************************/
bool isCircular(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // To determine if the cycle starts at the head
            Node* temp = head;
            while (temp != slow) {
                temp = temp->next;
                slow = slow->next;
            }
            return temp == slow;
        }
    }
    return false;
}

/*************************************************
    Main function to test the isCircular function
**************************************************/
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Test case 1: Non-circular list
    cout << "Test case 1 (Non-circular list): " << (isCircular(head) ? "Circular" : "Not Circular") << endl;

    // Making the list circular: 5 -> 3
    head->next->next->next->next->next = head->next->next;
    
    // Test case 2: Circular list
    cout << "Test case 2 (Circular list): " << (isCircular(head) ? "Circular" : "Not Circular") << endl;

    // Clean up the linked list nodes (this might not be necessary if using a circular list for testing)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
        if (head == temp->next) break; // Break if we are in a circular list
    }

    return 0;
}
