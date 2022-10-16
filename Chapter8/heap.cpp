#include <iostream>

int n; // size

// The children of the parent node at index i is at:
// Left child: 2i + 1
// Right child: 2i + 2

void heapify(int arr[], int i) {
    int smallest = i;
    int l = 2 * i + 1; // left child node
    int r = 2 * i + 2; // right child node

    // Check if left child is smaller than its parent
    if (l < n && arr[l] < arr[smallest]) smallest = l;

    // Check if right child is smaller than smallest
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    // If smallest is not parent
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, smallest);
    }
}

void buildHeap(int arr[]) {
    // Perform level order traversal from last non-leaf node and heapify each node
    for (int i = n; i >= 0; i--) {
        heapify(arr, i);
    }
}

int main() {
    int arr[] = { 4, 7, 2, 1, 3 };

    n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array representation before buildHeap is: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    buildHeap(arr);

    std::cout << "Array representation after buildHeap is: " << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}