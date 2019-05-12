#include<iostream>
using namespace std;
struct DStack{
    int capacity;
    int *arr;
    int top;
};
DStack* createStack(){
    DStack* s=new DStack;
    s->capacity=1;
    s->top=-1;
    s->arr=new int[s->capacity];
    return s;
}

bool isEmpty(DStack *s){
    if(s->top==-1){
        return true;
    }return false;
}
bool isFull(DStack* s){
    if(s->top==s->capacity-1){
        return true;
    }return false;
}
void doubleStack(DStack* s){
    int earlier_size=s->capacity;
    s->capacity=2*s->capacity;
    int* arr=new int[s->capacity];
    std::copy(s->arr,s->arr+earlier_size,arr);
    s->arr=arr;
}
void push(DStack* s,int x){
    if(isFull(s)){
        doubleStack(s);
    }
   ++(s->top);
   s->arr[s->top]=x;

}
int pop(DStack* s){
    if(isEmpty(s)){
        cout<<"Underflow";
        return -1;
    }else{
        return s->arr[s->top--];
    }
}
int main(){
    DStack* s=createStack();
    push(s,1);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,56);
    push(s,3);
    push(s,9);
    push(s,8);
    push(s,7);
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
     cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
     cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
     cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
     cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
}
