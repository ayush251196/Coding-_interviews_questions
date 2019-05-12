#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MinHeap{
	public:
		vector<int> arr;
		int heapSize;
		MinHeap(){
			//arr=new vector<int>();
			heapSize=0;
		}
		int parent(int i){
			return (i-1)/2;
		}
		void insert(int key){
			int i=heapSize;
			arr.push_back(key);
			heapSize++;
			while(i!=0 and arr[parent(i)]>arr[i]){
				swap(arr[parent(i)],arr[i]);
				i=parent(i);
			}
		}
		void heapify(int i){
			int lc=2*i+1;
			int rc=2*i+2;
			
			if(lc<heapSize and arr[lc]<arr[rc]){
				if(arr[lc]<arr[i]){
					swap(arr[lc],arr[i]);
					heapify(lc);
				}
			}
			else if(rc<heapSize and arr[rc]<arr[lc]){
				if(arr[rc]<arr[i]){
					swap(arr[rc],arr[i]);
					heapify(rc);
				}
			}
			
		}
		void decreaseKey(int i,int val){
			arr[i]=val;
			while(i!=0 and arr[parent(i)]>arr[i]){
				swap(arr[parent(i)],arr[i]);
				i=parent(i);
			}
		}
		void increaseKey(int i,int val){
			arr[i]=val;
			heapify(i);
		}
		
		int extractMin(){
			if(heapSize==0){
				return INT_MIN;
			}
			int m=arr[0];
			arr[0]=arr[heapSize-1];
			heapSize--;
			heapify(0);
			return m;
			
		}
		void deleteKey(int i){
			if(heapSize==0){
				cout<<"Underflow\n";
				return ;
			}
			heapSize--;
			decreaseKey(i,INT_MIN);
			extractMin();
		}
		void buildHeap(vector<int> arr){
			heapSize=arr.size();
			this->arr=arr;
			arr.clear();
			for(int i=(heapSize-1)/2;i>=0;i--){
				heapify(i);
			}
		}
		
		
};
int main(){
	MinHeap h;
	h.insert(3);
	h.insert(2);
	h.insert(1);
	h.insert(15);
	h.insert(5);
	h.insert(4);
	h.insert(45);
//	cout<<h.extractMin()<<endl;
//	cout<<h.extractMin()<<endl;
//	cout<<h.extractMin()<<endl;
//	cout<<h.extractMin()<<endl;
//	cout<<h.extractMin()<<endl;
	vector<int> v={-5,4,3,2,1};
	h.buildHeap(v);
	cout<<h.extractMin()<<endl;
	cout<<h.extractMin()<<endl;
	

}
