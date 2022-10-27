#include <iostream>

class Node {
private:
    int data;
    Node* left;
    Node* right;
    bool isRed = false;

    Node* makeNode(int val) {
        Node* node = new Node(val);
        node->left = node->right = nullptr;
        return node;
    }

public:
    Node(int val) : data{ val } {}

    Node* pushNode(int val, Node* node) {

        if(val < node->data) {
            
        }

        if(val > node->data) {

        }

    }

};

