#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solutions {
public :
    Node *insertAtHead(Node *head, int value) {
        if(head == nullptr) {
            // no linkedlist exists
            head = new Node(value);
        } else {
            Node *temp = new Node(value);
            temp->next = head;
            head = temp;
        }
        return head;
    }

    Node *insertAtTail(Node *head, int value) {
        if(head == nullptr) {
            head = new Node(value);
        } else {
            Node *tail = head;

            while(tail->next != nullptr) {
                tail = tail->next;
            }

            // we have reached the tail or the last node
            Node *temp = new Node(value);
            tail->next = temp;
            tail = temp;
        }
        return head;
    }

    Node *insertAtPosition(Node *head, int position, int value) {
        if(position == 0) {
            // insert at head
            head = insertAtHead(head, value);
            return head;
        }

        Node *current = head;
        for(int i=0; i<((position-1) && (current != nullptr)); i++) {
            current = current->next;
        }

        if(current == nullptr) {
            return head;    // position is out of bound
        }

        // now we will create a new node
        Node *temp = new Node(value);
        temp->next = current->next;
        current->next = temp;

        return head;
    }

};

int main(){

    return 0;
}