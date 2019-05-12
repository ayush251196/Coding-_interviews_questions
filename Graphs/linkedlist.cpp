#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* createNode(int data){
    Node* n=new Node;
    n->data=data;
    n->next=nullptr;
    return n;
}
void addAtEnd(int data,Node** head){
    Node* newNode=createNode(data);
    if(*head==nullptr){
        *head=newNode;
    }else{
        Node* temp=*head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void addAtHead(int data,Node** head){
    Node* newNode=createNode(data);
    if(*head==nullptr){
        *head=newNode;
    }else{
        newNode->next=*head;
        *head=newNode;
    }
}
void traverse(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void reverseList(Node** head){
    if(head!=nullptr){
        Node* h=*head;
        Node* pp=nullptr;
        Node* prev=h;
        Node* curr=h->next;
        while(curr!=nullptr){
            prev->next=pp;
            Node* next=curr->next;
            curr->next=prev;
            pp=prev;
            prev=curr;
            curr=next;
        }
        *head=prev;
    }
}
int main(){
    Node* head=createNode(1);
    addAtEnd(2,&head);
    addAtEnd(3,&head);
    addAtEnd(4,&head);
    addAtEnd(5,&head);
    addAtEnd(6,&head);
    addAtEnd(9,&head);
    traverse(head);
    addAtHead(10,&head);
    traverse(head);
    addAtHead(11,&head);
    traverse(head);
    addAtHead(12,&head);
    traverse(head);
    reverseList(&head);
    traverse(head);

}
