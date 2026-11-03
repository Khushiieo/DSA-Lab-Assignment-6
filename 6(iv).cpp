#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        Node* n = new Node{s[i], tail, NULL};

        if (head == NULL)
            head = n;
        else
            tail->next = n;

        tail = n;
    }

    Node* left = head;
    Node* right = tail;

    bool palindrome = true;

    while (left != NULL && right != NULL) {
        if (left == right || left->next == right)
            break;

        if (left->data != right->data) {
            palindrome = false;
            break;
        }

        left = left->next;
        right = right->prev;
    }

    if (palindrome)
        cout << "True";
    else
        cout << "False";

    return 0;
}
