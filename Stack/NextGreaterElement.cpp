#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={2,31,13,12,18,23,10};
    int n=sizeof(arr)/sizeof(int);
    int arr1[n];
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.empty()==false and arr[i]>st.top()){
            st.pop();
        }
        if(!st.empty())
            arr1[i]=st.top();
        else
            arr1[i]=-1;
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"-->"<<arr1[i]<<endl;
    }
}
