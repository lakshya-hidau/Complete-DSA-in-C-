#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;  
    }
};

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);

    // Empty list
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = nullptr;
    Node* ansTail = nullptr;

    while (first != nullptr || second != nullptr || carry != 0) {
        int val1 = (first != nullptr) ? first->data : 0;
        int val2 = (second != nullptr) ? second->data : 0;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtTail(ansHead, ansTail, digit);

        if (first != nullptr) first = first->next;
        if (second != nullptr) second = second->next;
    }

    return ansHead;
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

Node* addTwoLists(Node* &first, Node* &second) {
    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first, second);

    ans = reverse(ans);

    return ans;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create first linked list: 3 -> 4
    Node* first = new Node(3);
    first->next = new Node(4);

    cout << "First List: ";
    print(first);

    // Create second linked list: 4 -> 6 -> 5
    Node* second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5);

    cout << "Second List: ";
    print(second);

    // Add two linked lists
    Node* result = addTwoLists(first, second);

    // Print the result linked list
    cout << "Result List: ";
    print(result);

    return 0;
}
