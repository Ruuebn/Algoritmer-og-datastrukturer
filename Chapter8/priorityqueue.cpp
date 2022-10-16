#include <iostream>

typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;

Node* newNode(int d, int p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

int peek(Node** head) {
    return (*head)->data;
}

void pop(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node** head, int d, int p) {
    Node* start = (*head);
    Node* temp = newNode(d, p);

    // The head of list has higher priority than new node
    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    }
    else {
        // Traverse the list and find a position to insert new node
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        // Either at the ends of the list or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

bool isEmpty(Node** head) {
    return (*head) == NULL;
}

int main() {
    // Create a priority queue
    // 7 -> 4 -> 5 -> 6
    Node* pq = newNode(4, 1);
    push(&pq, 5, 2);
    push(&pq, 6, 3);
    push(&pq, 7, 0);

    while (!isEmpty(&pq)) {
        std::cout << " " << peek(&pq);
        pop(&pq);
    }
    return 0;
}