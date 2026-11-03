#include <iostream>
using namespace std;

struct Node {
    int data;
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

        Node* newNode = new Node{x, NULL};

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL)
        tail->next = head;

    Node* temp = head;

    if (head != NULL) {
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Size of Circular Linked List: " << count;

    return 0;
}
