#include <iostream>


// Make a struct for datatype Node, used in binary tree
// Node has data, and a pointer to its left and right children
struct Node {
    int data;
    Node* left, *right;
};

// Function to create nodes on a binary tree
Node* newNode(int item) {
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the depth of a binary tree
// The function takes in the root, which can also be a relative root,
// And finds the height from the root to the number you want to search for
int findDepth(Node* root, int x) {
    if(root == NULL) {
        return -1;
    }

    int dist = -1;

    // If the data has been found, return 0
    if(root->data == x) return 0;
    // If 0 was just returned, or if dist > 0, increment dist
    if((dist = findDepth(root->left, x) >= 0) || (dist = findDepth(root->right, x) >= 0)) return dist + 1;

    return dist;
}

// Utilisation function for findHeight()
int findHeightUtil(Node* root, int x, int& height) {
    if(root == NULL) return -1;

    // Find the left and right heights of children nodes
    int leftHeight = findHeightUtil(root->left, x, height);
    int rightHeight = findHeightUtil(root->right, x, height);

    // Compare children heights and add 1 to get correct height
    int ans = std::max(leftHeight, rightHeight) + 1;
    if(root->data == x) height = ans;

    return ans;
}

// Find the height of a binary tree to a given Node with data x
int findHeight(Node* root, int x) {
    int h = -1;
    int maxHeight = findHeightUtil(root, x, h);
    return h;
}

// Implementation without use of classes
int main() {
    Node* root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->left->right->right = newNode(45);
    root->right->left = newNode(30);
    root->right->right = newNode(35);

    int k = 25;

    std::cout << "Depth: " << findDepth(root, k) << "\n";
    std::cout << "Height: " << findHeight(root, k);

}