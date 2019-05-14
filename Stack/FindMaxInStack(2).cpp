#include<iostream>
using namespace std;
class Stack{
    public :
    int SIZE,top,MAX;
    int *arr;
    Stack(int s){
        SIZE=s;
        top=-1;
        arr=new int[SIZE];
    };
    void push(int data){
        if(top+1==SIZE){
            cout<<"Overflow\n";
        }else if(top==-1){
            arr[++top]=data;
            MAX=data;
        }else if(data<=MAX){
            arr[++top]=data;
        }else{
            arr[++top]=2*data-MAX;
            MAX=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow\n";
        }else if(arr[top]<=MAX){
            cout<<"Popped "<<arr[top--]<<endl;
        }else{
            cout<<"Popped "<<MAX<<endl;
            MAX=2*MAX-arr[top--];
        }
    }
    void findMax(){
        if(top!=-1)
            cout<<"Maximum is "<<MAX<<endl;
        else
            cout<<"Underflow\n";
    }

};
int main(){
    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(9);
    st.push(10);
    st.push(5);
    st.push(2);
    st.findMax();
    st.pop();
    st.findMax();
    st.pop();
    st.findMax();
    st.pop();
    st.findMax();
    st.pop();
    st.findMax();
    st.pop();
    st.pop();
    st.pop();
    st.findMax();

}
