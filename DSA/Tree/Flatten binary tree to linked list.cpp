#include <iostream>
using namespace std;

class tNode {
public:
    int data;
    tNode* left;
    tNode* right;

    tNode(int d) : data(d), left(NULL), right(NULL) {}
};

void flatten(tNode* root) {
    tNode* curr = root;
    while (curr != NULL) {
        if (curr->left) {
            tNode* pred = curr->left;
            while (pred->right) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

tNode* newtNode(int data) {
    return new tNode(data);
}

void cleanup(tNode* root) {
    while (root != NULL) {
        tNode* temp = root;
        root = root->right; // Move to the next node
        delete temp; // Delete the current node
    }
}

int main() {
    tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(5);
    root->left->left = newtNode(3);
    root->left->right = newtNode(4);

    flatten(root);

    // Print the flattened tree
    tNode* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

    // Cleanup memory
    cleanup(root);

    return 0;
}
