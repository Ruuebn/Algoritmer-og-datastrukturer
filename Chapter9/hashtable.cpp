#include <iostream>
#include <vector>

// unfinished

template <class T>
class Node {
private:
    static inline size_t size = 0;
    T val;
    Node* next;
public:
    Node(T v) : val{v} {
        size++;
    }
    ~Node() {
        delete this;
        delete next;
    }

    Node* getNext() { return next; }
    T value() { return val; }
    Node* getNodeAt(int idx) {
        Node* it = this;
        for(; idx < size; idx++) {
            if(it->next == nullptr) break;
            it = it->next;
        }
        return this;
    }

    void add(T v) {
        if(next != nullptr) {
            next->addNode(v);
        } else {
            next = new Node(v);
        }
    }
    void remove() {
        delete getNodeAt(size - 1);
    }

};

class Item {
private:
    int name;
public:
    Item(int n) : name{n} {}
    int name() { return name; }
};

class HashTable {
private:
    int prime;

public:
    HashTable(int p) : prime{ p } {}
};

int main() {

}