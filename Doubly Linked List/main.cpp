#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// Time: O(1), Space: O(1)
Node* insertAtFront(Node* head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;

    return head;
}

// Time: O(n), Space: O(1)
Node* insertAtLast(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        return temp;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;
    temp->prev = current;

    return head;
}

// Time: O(n), Space: O(1)
Node* Delete(Node* head, int x) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return head;
    }

    Node* temp = head;
    
    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    // If node is not found
    if (temp == NULL) {
        cout << "Element not found in the list.\n";
        return head;
    }

    // If the node to delete is the head
    if (temp == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    // If the node is somewhere else in the list
    else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    
    delete temp;
    return head;
}

void Print(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List is: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void search(Node* head, int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            cout << "Found!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found!\n";
}

int main() {
    Node* head = NULL;

    head = insertAtLast(head, 1);
    head = insertAtLast(head, 2);
    head = insertAtLast(head, 3);
    head = insertAtLast(head, 4);
    head = insertAtFront(head, 5);

    Print(head);

    int x, y;
    cout << "Enter number to be searched: ";
    cin >> x;
    search(head, x);

    cout << "Enter number to be deleted: ";
    cin >> y;
    head = Delete(head, y);

    Print(head);

    return 0;
}
