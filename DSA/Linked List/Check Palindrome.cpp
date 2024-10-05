#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;  // Use nullptr instead of NULL
    }
};

void print(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Linked List is Palindrome" << endl;
        return true;
    }

    // Step 1: Find middle of the linked list
    Node* middle = getMiddle(head);

    // Step 2: Reverse the second half of the linked list
    Node* secondHalf = reverse(middle->next);
    middle->next = secondHalf;

    // Step 3: Compare the first and reversed second half
    Node* p1 = head;
    Node* p2 = secondHalf;

    bool palindrome = true;
    while (p2 != nullptr) {
        if (p1->data != p2->data) {
            palindrome = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Step 4: Restore the linked list to its original state
    Node* restoredSecondHalf = reverse(secondHalf);
    middle->next = restoredSecondHalf;

    if (palindrome) {
        cout << "Linked List is Palindrome" << endl;
    } else {
        cout << "Linked List is not Palindrome" << endl;
    }

    return palindrome;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << "Given Linked List is : " << endl;
    print(head);

    isPalindrome(head);

    return 0;
}
