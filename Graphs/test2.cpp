#include<iostream>
using namespace std;
struct Node{
Node *next=NULL;
int data;
};
class LinkedList{
    public:
    struct Node* head=NULL;
    struct Node* endNode=NULL;
    LinkedList(int data){
        this->head=new Node;
        this->head->data=data;
        this->endNode=head;
    }
    void append(int data){
        Node* node=new Node;
        node->data=data;
        this->endNode->next=node;
        this->endNode=node;
    }
    void addInFront(int data){
        Node* node=new Node;
        node->data=data;
        node->next=head;
        head=node;
    }
    void traverse(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main(){
    LinkedList l(4);
    l.append(5);
    l.append(6);
    l.append(7);
    l.append(8);
    l.append(9);
    l.append(10);
    l.traverse();
}
