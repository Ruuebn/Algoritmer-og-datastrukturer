#include <iostream>
#include <memory>

// Exercise: Implement a BST where you can search a value, insert
// a new value, and print the output with preorder traversal function

// Node class used to represent the BST
class Node {
    using nodeptr = std::shared_ptr<Node>;
private:
    int data;
    nodeptr left, right;

    // Auxiliary function for pushNode(), not used outside of it
    nodeptr makeNode(int val) {
        nodeptr node = std::make_shared<Node>(val);
        node->left = node->right = nullptr;
        return node;
    }

public:
    // Node constructor is needed for std::make_shared and makeNode()
    Node(int d) : data{ d } {}

    // Insertion of value - 1/3
    // Pushes node into the BST, function chaining is possible
    nodeptr pushNode(int val, nodeptr node) {
        // Create a new node if the node is empty
        if (node == nullptr) return makeNode(val);

        // If not, search recursively until an empty node is found
        if (val < node->data) {
            node->left = pushNode(val, node->left);
        }
        else if (val > node->data) {
            node->right = pushNode(val, node->right);
        }
        return node;
    }

    // Preorder function - 2/3
    // Print preorder
    void preorder(nodeptr root) {
        if (root != nullptr) {
            // Print root first, unlike postorder where root is printed last
            std::cout << root->data << " ";

            // Then traverse recursively through the BST
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Search for number - 3/3
    // Search for a given integer within the BST, return true if it exists, else return false
    bool findNum(int val, nodeptr root) {
        // Return false if the BST is empty
        // or has come to a leaf without finding the correct number
        if (root == nullptr) return false;

        // If val is less, recursively search left
        if (val < root->data) {
            return findNum(val, root->left);
        }
        // If val is greater, recursively search right
        else if (val > root->data) {
            return findNum(val, root->right);
        }
        // If val is equal, we've found it, return true
        else if (val == root->data) {
            return true;
        }
    }
};

// Driver code
int main() {

    // Create the Node object
    std::shared_ptr<Node> root = std::make_shared<Node>(8);
    auto data = { 3, 1, 6, 4, 7, 10, 14, 13 };

    // Push all values shown in the task
    for (auto e : data) {
        root->pushNode(e, root);
    }

    // Print preorder
    root->preorder(root);
    std::cout << std::endl;

    // Search value
    std::cout << std::boolalpha << root->findNum(6, root) << std::endl;
    std::cout << std::boolalpha << root->findNum(17, root) << std::endl;

}
