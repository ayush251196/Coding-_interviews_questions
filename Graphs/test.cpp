#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<bool> *v=new vector<bool>(10,false);
	unordered_set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(0);
	for(auto x:set){
		cout<<x<<" ";
	}
//	cout<<v->at(1)<<endl;
}
