#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void insertFirst(int x) {
        Node* n = new Node{x, NULL};

        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL};

        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void insertAfter(int key, int x) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == key) {
                Node* n = new Node{x, temp->next};
                temp->next = n;
                cout << "Inserted successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found\n";
    }

    void insertBefore(int key, int x) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key) {
            insertFirst(x);
            return;
        }

        Node* temp = head;

        while (temp->next != head && temp->next->data != key)
            temp = temp->next;

        if (temp->next == head) {
            cout << "Node not found\n";
            return;
        }

        Node* n = new Node{x, temp->next};
        temp->next = n;
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->data == key) {
                if (curr->next == curr) {
                    head = NULL;
                }
                else if (curr == head) {
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
                else {
                    prev->next = curr->next;
                }

                delete curr;
                cout << "Node deleted\n";
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != head);

        cout << "Node not found\n";
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
};

int main() {
    CircularList l;
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
