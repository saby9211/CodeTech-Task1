// Implementation Of Singly Linked List
#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}
    Node(int x) : data(x), next(NULL) {}
};

// Time : O(1), Space : O(1)
Node* insertAtFront(Node* head, int x) {
    Node* temp = new Node(x);
    temp -> next = head;
    head = temp;

    return head;
}
// Time : O(n), Space : O(1)
Node* insertAtLast(Node* head, int x) {
    if(head == NULL) {
        head = new Node(x);
        return head;
    }
    Node* temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = new Node(x);
    return head;
}
// Time : O(n), Space : O(1).
Node* Delete(Node* head, int x) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL && temp -> data != x) {
        prev = temp;
        temp = temp -> next;
    }

    if(temp == head) {
        head = head -> next;
        delete temp;
    } 
    else {
        prev -> next = temp -> next;
        delete temp;
    }
    return head;
}

void Print(Node* head) {
    Node* temp = head;
    cout << "Linked List is : ";
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
    
}

void search(Node* head, int x) {
    Node* temp = head;
   
    while(temp != NULL) {
        if(temp -> data == x) {
            cout << "Found !" << "\n";
            return;
        }
        temp = temp -> next;
    }
    cout << "Not Found !\n";
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
    cout << "Enter number to be searched : ";
    cin >> x;
    search(head, x);

    cout << "Enter number to be deleted : ";
    cin >> y;
    head = Delete(head, y);
    Print(head);




    return 0;
}