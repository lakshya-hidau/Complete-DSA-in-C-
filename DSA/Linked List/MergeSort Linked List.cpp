#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

node* findMid(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    node* slow = head;
    node* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    node* ans = NULL;
    
    if (left->data < right->data) {
        ans = left;
        ans->next = merge(left->next, right);
    } else {
        ans = right;
        ans->next = merge(left, right->next);
    }
    
    return ans;
}

node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = new node(5);
    head->next = new node(3);
    head->next->next = new node(2);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(4);

    cout << "Original Linked List" << endl;
    print(head);

    head = mergeSort(head); // Update the head with the sorted list

    cout << "Sorted Linked List using Merge Sort" << endl;
    print(head);

    return 0;
}
