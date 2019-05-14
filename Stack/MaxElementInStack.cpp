#include<iostream>

using namespace std;

struct Pair{
    int X,Lmax;
    Pair(){

    }
    Pair(int x,int localMax){
        X=x;
        Lmax=localMax;
    }
};
struct Stack{
    int top,SIZE;
    Pair *arr;

    Stack(int s){
        SIZE=s;
        top=-1;
        arr=new Pair[SIZE];
    }

    push(int x){
        if(top+1==SIZE){
            cout<<"Overflow\n";
        }else{
            if(x>arr[top].Lmax or top==-1){
                Pair p(x,x);
                arr[++top]=p;
            }else{
                Pair p(x,arr[top].Lmax);
                arr[++top]=p;
            }
        }
    }
    void pop(){
        if(top==-1)
            cout<<"Underflow\n";
        else{
            cout<<"Popped "<<arr[top--].X<<endl;
        }

    }
    int findMax(){
        if(top>=0)
            return arr[top].Lmax;
        else
            cout<<"Underflow\n";
    }
};

int main(){
    Stack st(10);
    st.push(13);
    st.push(9);
    st.push(14);
    st.push(11);
    st.push(33);
    cout<<st.findMax()<<endl;
    st.pop();
    st.pop();
    cout<<st.findMax();
}
