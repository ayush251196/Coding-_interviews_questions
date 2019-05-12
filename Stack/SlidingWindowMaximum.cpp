#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    int k=3;
    int arr[]={2,31,13,12,18,23,10,5,2,1,1,2,2,3};
    int n=sizeof(arr)/sizeof(int);
    int arr1[n];
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty())
            arr1[i]=n;
        else
            arr1[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"-->"<<arr1[i]<<endl;
    }

    int j=0;
    for(int i=0;i<=n-k;i++){
        while(j<i or arr1[j]<=i+k-1)
            j++;
        cout<<arr[j]<<" ";
    }

}
