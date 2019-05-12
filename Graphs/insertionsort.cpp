#include<iostream>
using namespace std;
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int len=sizeof(arr)/sizeof(int);
    for(int i=1;i<len;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

}
