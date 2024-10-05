#include <iostream>
#include <unordered_map>
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

Node *removeDuplicates(Node *head)
{
    if(head == NULL) {
        return NULL;
    }

    unordered_map <int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        if(visited[curr->data] == true) {
            curr = curr -> next;
            delete (prev->next);
            prev -> next = curr;
            continue;
        }
        visited[curr->data] = true;
        prev = curr;
        curr = curr -> next;
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
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next->next = new Node(2);
    cout << "This is original unsorted linked list" << endl;
    print(head);
    cout << endl;

    cout << "This Linked List has no Duplicate element ." << endl;
    removeDuplicates(head);
    print(head);
   

    return 0;
}