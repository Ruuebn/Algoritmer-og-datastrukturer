#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class MinHeap {
private:
    std::vector<T> items;

    int leftChildIdx(int parentIdx) { return 2 * parentIdx + 1; }
    int rightChildIdx(int parentIdx) { return 2 * parentIdx + 2; }
    int parentIdx(int childIdx) { return (childIdx - 1) / 2; }

    bool hasRightChild(int idx) { return rightChildIdx(idx) < items.size(); }
    bool hasLeftChild(int idx) { return leftChildIdx(idx) < items.size(); }
    bool hasParent(int idx) { return parentIdx(idx) >= 0; }

    T leftChild(int idx) { return items[leftChildIdx(idx)]; }
    T rightChild(int idx) { return items[rightChildIdx(idx)]; }
    T parent(int idx) { return items[parentIdx(idx)]; }

    void swap(int idx, int jdx) {
        std::swap(items[idx], items[jdx]);
    }
    
public:
    MinHeap() {}

    T peek() {
        return items[0];
    }

    T poll() {
        T item = items[0];
        items[0] = items[items.size() - 1];
        items.erase(items.end() - 1);
        heapifyDown();
        return item;
    }

    void add(T item) {
        items.push_back(item);
        heapifyUp();
    }

    void heapifyUp() {
        int idx = items.size() - 1;
        while(hasParent(idx) && (parent(idx) > items[idx])) {
            swap(parentIdx(idx), idx);
            idx = parentIdx(idx);
        }
    }

    void heapifyDown() {
        int idx = 0;
        while(hasLeftChild(idx)) {
            int smallerChildIdx = leftChildIdx(idx);
            if(hasRightChild(idx) && (rightChild(idx) < leftChild(idx))) {
                smallerChildIdx = rightChildIdx(idx);
            }
            if(items[idx] < items[smallerChildIdx]) {
                break;
            } else {
                swap(idx, smallerChildIdx);
            }
            idx = smallerChildIdx;
        }
    }

    void displayHeap() {
        for(auto e : items) 
            std::cout << e << " ";
        std::cout << std::endl;
    }

    
};

int main() {
    MinHeap<int> heap;

    int list[] = {3, 2, 9, 10, 14, 5, 32, 26};

    for(auto e : list) {
        heap.add(e);
    }

    heap.displayHeap();

}
