#include <iostream>

// This class implements a binary search tree as well as a function
// to print out the contents of the BST using postorder

// The struct node is self-referential, much like as you can see in ex.cpp
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// This is a very C-like style to implement, especially when using malloc()
struct Node* createNode(int val) {
    // Allocate memory for the node temp
    struct Node* temp = (struct Node*)std::malloc(sizeof(struct Node));
    // Initialise attributes of temp
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
};

// Print BST in a postorder manner
void postorder(struct Node* root) {
    // Check if memory hasn't been allocated to the specific node in the branch
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
}

// Insertion in a BST is much easier than a BT, no need for chained functions
struct Node* insertNode(struct Node* node, int val) {
    // If the node reached has no memory allocated, create a new node and insert
    if (node == NULL) return createNode(val);

    // If the value given is less than the parent, place it to the left
    if (val < node->data) {
        node->left = insertNode(node->left, val);
    }
    // If the value given is more than the parent, place it to the right
    else if (val > node->data) {
        node->right = insertNode(node->right, val);
    }
    return node;
}

int main() {
    // Initialise root as NULL in order to allocate memory for it
    struct Node* root = NULL;
    root = insertNode(root, 6);

    // Insert all other children nodes
    insertNode(root, 4);
    insertNode(root, 8);
    insertNode(root, 1);
    insertNode(root, 5);

    // Print postorder 
    postorder(root);
}
