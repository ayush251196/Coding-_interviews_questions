#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
		int V;
		vector<int> *adj;
		Graph(int v){
			V=v;
			adj=new vector<int>[V];
		}
		void addEdge(int x,int y){
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int bfs(int i1,int i2){
			vector<int> distances(V,-1);
			distances[i1]=0;
			queue<int> q;
			q.push(i1);
			while(1){
				int size=q.size();
				if(!size)
					break;
				while(size--){
					int v=q.front();
					q.pop();
					for(auto x:adj[v]){
						if(distances[x]==-1){
							distances[x]=distances[v]+1;
							q.push(x);
						}if(x==i2){
							return distances[x];
						}
					}
				}
			}
			return -1;
		}
		
};
vector<int> seive(int n){
	vector<bool> prime(n+1,true);
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
	vector<int> pnos;
	for(int i=1000;i<=n;i++){
		if(prime[i]){
			pnos.push_back(i);
		}
	}
	return pnos;
}
		
 bool compare(int a,int b){
	string sa=to_string(a);
	string sb=to_string(b);
	int c=0;
	for(int i=0;i<4;i++){
		if(sa[i]!=sb[i]){
			c++;
		}
	}
	return (c==1); 
}
int implement(int p1,int p2){
	int r=9999;
	int i1,i2;
	vector<int> prime;
	prime=seive(9999);
	int len=prime.size();
	Graph g(len);
	for(int i=0;i<prime.size()-1;i++){
		for(int j=i+1;j<prime.size();j++){
			if(compare(prime[i],prime[j])){
				g.addEdge(i,j);
			}
		}
	}
	for(int i=0;i<prime.size();i++){
		if(prime[i]==p1){
			i1=i;
		}if(prime[i]==p2){
			i2=i;
		}
	}
	return g.bfs(i1,i2);
}
int main(){
	int x,y;
	cin>>x>>y;
	cout<<implement(x,y);
}
