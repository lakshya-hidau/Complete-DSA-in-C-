#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*> nodeMap;
        
        // Create copies of nodes without random pointers
        Node* current = head;
        while (current != nullptr) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // Set the next and random pointers of the copied nodes
        current = head;
        while (current != nullptr) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }
        
        return nodeMap[head];
    }
};

int main() {
    // Example usage to test copyRandomList function
    
    // Create a sample linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    // Assign random pointers
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head;       // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2
    
    // Create a Solution object
    Solution sol;
    
    // Copy the linked list with random pointers
    Node* copiedList = sol.copyRandomList(head);
    
    // Output the original and copied lists (for demonstration purposes)
    cout << "Original List:" << endl;
    Node* curr = head;
    while (curr != nullptr) {
        cout << "Node(" << curr->val << ") -> ";
        if (curr->random)
            cout << "Random(" << curr->random->val << ")";
        else
            cout << "Random(nullptr)";
        cout << endl;
        curr = curr->next;
    }
    
    cout << endl << "Copied List:" << endl;
    curr = copiedList;
    while (curr != nullptr) {
        cout << "Node(" << curr->val << ") -> ";
        if (curr->random)
            cout << "Random(" << curr->random->val << ")";
        else
            cout << "Random(nullptr)";
        cout << endl;
        curr = curr->next;
    }
    
    return 0;
}
