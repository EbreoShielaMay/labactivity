#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class linked_list {
private:
    node *head, *tail;

public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
   
    void insert_start(int v) {
        node *temp = new node;
        temp->data = v;
        temp->next = head;
        head = temp;
    }
   
    void insert_anypos(int pos, int v) {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        temp->data = v;
        pre->next = temp;
        temp->next = cur;
    }
   
    void del_first() {
        node *tmp = new node;
        tmp = head;
        head = head->next;
        delete tmp;
    }
   
    void del_last() {
        node *cur = new node;
        node *pre = new node;
        cur = head;
        while (cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        tail = pre;
        pre->next = NULL;
        delete cur;
    }
   
    void delete_pos(int pos) {
        node *cur = new node;
        node *pre = new node;
        cur = head;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
};

int main() {
    linked_list a;
    int choice, value, pos;

    while (true) {
        cout << "1. Add Item" << endl;
        cout << "2. Delete Item" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                cout << "1. Insert at start" << endl;
                cout << "2. Insert at end" << endl;
                cout << "3. Insert at position" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    a.insert_start(value);
                } else if (choice == 2) {
                    a.addNode(value);
                } else if (choice == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    a.insert_anypos(pos, value);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 2:
                cout << "1. Delete from start" << endl;
                cout << "2. Delete from end" << endl;
                cout << "3. Delete from position" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    a.del_first();
                } else if (choice == 2) {
                    a.del_last();
                } else if (choice == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    a.delete_pos(pos);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 3:
                a.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
