#include<bits/stdc++.h>
using namespace std;

class Node {
public : 
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* createLinkedList(vector<int>& arr){
    if(arr.size() == 0) return nullptr;

    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<arr.size(); i++) {
        if(head == nullptr) {
            // then there's no linkedlist created yet
            head = new Node(arr[i]);
            tail = head;
        } else {
            // there's already a linkedlist exists
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    if(head == nullptr) return;
    Node *temp = head;
    
    while(temp != nullptr){
        cout<<temp->data<<" "<<temp->next<<"\n";
        temp = temp->next;
    }
}
class Solution {
public:
    // Only solve here
    int length(Node* head) {
        if(head == nullptr) return 0;

        Node *temp = head;
        int count = 0;
        
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool search(Node* head, int target){
        if(head == nullptr) return false;
        Node* temp = head;

        while(temp != nullptr){
            if(temp->data == target) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int sum(Node* head){
        if(head == nullptr) {
            return 0;
        }
        Node* temp = head;
        int sum = 0;
        while(temp != nullptr){
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int maximum(Node* head){
        if(head == nullptr) return INT_MIN;

        Node *temp = head;
        int max = INT_MIN;

        while(temp != nullptr) {
            if(temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    int minimum(Node* head) {
        if(head == nullptr) return INT_MAX;
        Node *temp = head;
        int min = INT_MAX;

        while(temp != nullptr) {
            if(temp->data < min) {
                min = temp->data;
            }
            temp = temp->next;
        }
        return min;
    }

    bool allPositive(Node* head) {
        if(head == nullptr) return false;    // i'll ask the interviewer in this case

        Node* temp = head;
        while(temp != nullptr) {
            if(temp->data < 0) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    int findFirstOccurrence(Node *head, int target) {
        if(head == nullptr) return -1;

        Node *temp = head;
        int index = 0;

        while(temp != nullptr) {
            if(temp->data == target) {
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;
    }



};


int main(){
    vector<int> arr = {10,20,30};
    Node *head = createLinkedList(arr);
    cout<<"head is at : "<<head<<"\n";
    cout<<"value at head : "<<head->data<<"\n";
    printLinkedList(head);

    Solution obj;
    cout<<"Length of the linkedlist is : "<<obj.length(head)<<endl;
    cout<<"Search the value 10 in the linkedlist : "<<obj.search(head, 10)<<endl;
    cout<<"Search the value 50 in the linkedlist : "<<obj.search(head, 50)<<endl;
    cout<<"sum the values in the linkedlist is : "<<obj.sum(head)<<endl;
    cout<<"max value in the linkedlist is : "<<obj.maximum(head)<<endl;
    cout<<"mim value in the linkedlist is : "<<obj.minimum(head)<<endl;
    cout<<"Is all the value in the linkedlist are pos : "<<obj.allPositive(head)<<endl;
    cout<<"First occurence of 10 is "<<obj.findFirstOccurrence(head,10)<<endl;
    cout<<"First occurence of 20 is "<<obj.findFirstOccurrence(head,20)<<endl;
    cout<<"First occurence of 30 is "<<obj.findFirstOccurrence(head,30)<<endl;
    cout<<"First occurence of 40 is "<<obj.findFirstOccurrence(head,40)<<endl;

    return 0;
}