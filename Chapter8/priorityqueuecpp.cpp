#include <iostream>
#include <memory>

class Node {
private:
    int data;
    int priority;
    Node* next;

    Node* newNode(int d, int p) {
        Node* node = new Node(d, p);
        node->next = nullptr;

        return node;
    }

public:
    Node(int d, int p) : data{ d }, priority{ p } {}

    int peek() {
        return data;
    }

    void pop(Node** head) {
        Node* temp = (*head);
        (*head) = (*head)->next;
        delete temp;
    }

    void push(Node** head, int d, int p) {
        Node* start = (*head);
        Node* temp = newNode(d, p);

        if ((*head)->priority > p) {
            temp->next = (*head);
            (*head) = temp;
        }
        else {
            while (start->next != nullptr && start->next->priority < p) {
                start = start->next;
            }

            temp->next = start->next;
            start->next = temp;
        }
    }

    bool isEmpty(Node** head) {
        return (*head) == nullptr;
    }
};

int main() {
    Node* pq = new Node(4, 1);

    pq->push(&pq, 5, 2);
    pq->push(&pq, 6, 3);
    pq->push(&pq, 7, 0);

    while (!pq->isEmpty(&pq)) {
        std::cout << " " << pq->peek();
        pq->pop(&pq);
    }

    delete pq;
}