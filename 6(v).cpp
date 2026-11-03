#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n, x;

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

    int choice;

    cout << "Make list circular? (1.Yes / 0.No): ";
    cin >> choice;

    if (choice == 1 && tail != NULL)
        tail->next = head;

    Node* temp = head;
    bool circular = false;

    if (head != NULL) {
        temp = head->next;

        while (temp != NULL && temp != head) {
            temp = temp->next;
        }

        if (temp == head)
            circular = true;
    }

    if (circular)
        cout << "True";
    else
        cout << "False";

    return 0;
}
