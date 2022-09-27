#include <iostream>
#include <memory>

// There's no real need for a template class when
// comparator operations typically are needed only for integers/floats
// But it is implemented as a template class either way

template <typename T>
class Node {
    using nodeptr = std::shared_ptr<Node<T>>;
private:
    T data;
    nodeptr left, right;
public:

    Node(T d) : data{ d } {}

    // The implementation here and in other functions are generally the same from the other file
    // So it isn't too interesting
    // Although it can definetly be better
    nodeptr createNode(T val) {
        nodeptr node = std::make_shared<Node<T>>(val);
        node->left = node->right = nullptr;
        return node;
    }

    // Chaining functions is possible
    nodeptr insertNode(T val, nodeptr node) {
        // Create a new node if the node is empty
        if (node == nullptr) return createNode(val);

        if (val < node->data) {
            node->left = insertNode(val, node->left);
        }
        else if (val > node->data) {
            node->right = insertNode(val, node->right);
        }
        return node;
    }

    // Print postorder
    void postorder(nodeptr root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data << " ";
        }
    }

    // Print preorder
    void preorder(nodeptr root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Get functions
    T getData() {
        return data;
    }

    nodeptr getLeft() {
        return left;
    }

    nodeptr getRight() {
        return right;
    }
};


int main() {
    std::shared_ptr<Node<int>> node = std::make_shared<Node<int>>(44);

    // Just inserting tons of values
    node->insertNode(17, node)->insertNode(78, node);
    node->insertNode(32, node)->insertNode(50, node);
    node->insertNode(88, node);
    node->insertNode(48, node)->insertNode(62, node);

    // Printing both postorder and preorder traversal
    node->postorder(node);
    std::cout << std::endl;
    node->preorder(node);

}
