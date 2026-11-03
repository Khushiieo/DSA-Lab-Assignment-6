#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    void insertFirst(int x) {
        Node* n = new Node{x, NULL, head};

        if (head != NULL)
            head->prev = n;

        head = n;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL, NULL};

        if (head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int x) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found\n";
            return;
        }

        Node* n = new Node{x, temp, temp->next};

        if (temp->next != NULL)
            temp->next->prev = n;

        temp->next = n;
    }

    void insertBefore(int key, int x) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found\n";
            return;
        }

        if (temp == head) {
            insertFirst(x);
            return;
        }

        Node* n = new Node{x, temp->prev, temp};

        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found\n";
            return;
        }

        if (temp == head)
            head = temp->next;
        else
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted\n";
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Node not found\n";
    }

    void display() {
        Node* temp = head;

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyList l;
    int ch, x, key;

    do {
        cout << "\n1.Insert First\n2.Insert Last\n";
        cout << "3.Insert After\n4.Insert Before\n";
        cout << "5.Delete Node\n6.Search\n7.Display\n8.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> x;
                l.insertFirst(x);
                break;

            case 2:
                cin >> x;
                l.insertLast(x);
                break;

            case 3:
                cout << "Enter key and new value: ";
                cin >> key >> x;
                l.insertAfter(key, x);
                break;

            case 4:
                cout << "Enter key and new value: ";
                cin >> key >> x;
                l.insertBefore(key, x);
                break;

            case 5:
                cin >> key;
                l.deleteNode(key);
                break;

            case 6:
                cin >> key;
                l.search(key);
                break;

            case 7:
                l.display();
                break;
        }

    } while (ch != 8);

    return 0;
}
