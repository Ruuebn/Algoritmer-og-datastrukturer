#include <iostream>
#include <memory>

template <typename T>
class Node {

public:
    using nodeptr = std::shared_ptr<Node<T>>;

    nodeptr left, right;
    T d;

    // Need the constructor for std::make_shared (it calls the constructor and passes in the arguments)
    Node(T data) : d{ data } {}

    // newNode now takes in a value and a branch (for ex: newNode(6, root->left->right)
    // with this implementation, you can also chain together functions
    nodeptr newNode(T val, nodeptr& branch) {
        branch = std::make_shared<Node<T>>(val);
        branch->left = branch->right = nullptr;
        return branch;
    }

    // ... but you can also use the old implementation
    nodeptr newNode(T val) {
        nodeptr node = std::make_shared<Node<T>>(val);
        node->left = node->right = nullptr;
        return node;
    }

    T getData() {
        return d;
    }

    // I was too lazy to implement findDepth and findHeight

};

int main() {
    std::shared_ptr<Node<int>> root = std::make_shared<Node<int>>(4);
    std::cout << root->getData() << std::endl;

    // Chained functions, new implementation
    root->newNode(2, root->left)->newNode(3, root->right);
    // Old implementation accustomed to classes
    root->left->left = root->newNode(5);

    // You can also chain the old implementation, but it gets a bit out of hand
    root->left->right = root->newNode(7)->right->newNode(9);
    // and difficult to know where you have all your nodes... as if that wasn't a problem already

    std::cout << root->left->left->getData() << std::endl;
}