#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d){
     data=d;
     next=NULL;
    }
    Node(){}
};
class Stack{
    Node* head;
    public :Stack(){
        head=NULL;
    }
    void push(int data){
        Node* node=new Node(data);
        if(head==NULL){
            head=node;
        }else{
            node->next=head;
            head=node;
        }
    }
    void pop(){
        if(!head)
            cout<<"Underflow\n";
        else{
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            cout<<"popped "<<temp->data<<endl;
            free(temp);
        }
    }
    Node* getHead(){
        return head;
    }

};
void clone(Stack& s,Stack& d){
    Node* head=s.getHead();
    Node* prev=NULL;
    Node* next=head->next;
    while(head!=NULL){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    prev=NULL;
    next=head->next;
    while(head!=NULL){
        d.push(head->data);
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
}
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    Stack des;
    clone(st,des);
    des.pop();
    des.pop();
    des.pop();
    des.pop();
    st.pop();
}
