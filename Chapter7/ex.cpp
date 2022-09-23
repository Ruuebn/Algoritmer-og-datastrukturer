#include <iostream>

// Unfinished

struct Node {
    int data;
    Node* left, *right;
};



size_t findDepth(Node* root, int x) {
    if(root == NULL) {
        return 0;
    }

    int dist = -1;

    if(root->data == x) return 0;
    if((dist = findDepth(root->left, x) >= 0) || (dist = findDepth(root->right, x) >= 0)) return dist;
}




int main() {

}