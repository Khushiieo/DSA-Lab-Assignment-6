#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n, x, count = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        Node* newNode = new Node{x, tail, NULL};

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List: " << count;

    return 0;
}
