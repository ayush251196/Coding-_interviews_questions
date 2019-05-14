#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        next=NULL;
    }
    Node(){}

};
class Stack{
public:
    int top;
    Node* head;
    Stack(){
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
        if(head==NULL){
            cout<<"Underflow\n";
        }else {
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            cout<<"Popping "<<temp->data<<endl;
            free(temp);
        }
    }

    void reverse(){
        Node* head=this->head;
        Node* prev=NULL;
        Node* next=head->next;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        head=prev;
        this->head=head;
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    st.reverse();
    st.pop();
    st.pop();
    st.reverse();
    st.pop();

}
