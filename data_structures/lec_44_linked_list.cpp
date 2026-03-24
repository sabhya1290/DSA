#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void InsertAtHead(Node* &head, int d){
    
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    
}

void InsertAtTail(Node* &tail, int d){
    
    // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
    
}

// traversing a LinkedList
void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << ' ';
        // cout << temp -> next << endl;
        temp = temp -> next;
    }
}

int main(){
    // type of data structure which is connected to a node (node contain data + next node address)
    // LL = Dynamic DS
    // Insertion and Deletion is easy because no shift needed
    
    Node* node1 = new Node(10);

    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1 
    Node* head = node1;
    // // print(head);

    // InsertAtHead(head, 12);
    // InsertAtHead(head, 15);
    // print(head);
    
    // tail pointed to node1 
    Node* tail = node1;
    // print(tail);

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);

    print(head);



}