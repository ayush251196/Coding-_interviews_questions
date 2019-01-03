#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
	vector <int> *adj;
	
	int V;
	Graph(int v){
		this->V=v;
		adj=new vector<int>[v];
	}
	
	void addEdge(int x,int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void bfs(int s){
		vector<bool> visited(V,false);
		visited[s]=true;
		queue<int> q;
		q.push(s);
		while(1){
			int size=q.size();
			if(!size){
				break;
			}
			while(size--){
				int s=q.front();
				cout<<s<<" ";
				q.pop();
				for(auto x:adj[s]){
					cout<<"->"<<x<<" ";
					if(!visited[x]){
						q.push(x);
						visited[x]=true;
					}
				}cout<<endl;
			}
		}
	}
	
	void dfs(int s){
		stack<int> st;
		st.push(s);
		vector<bool> visited(V,false);
		visited[s]=true;
		while(1){
			int size=st.size();
			if(!size)
				break;
			while(size--){
				int s=st.top();
				cout<<s<<" ";
				st.pop();
				for(auto x:adj[s]){
					if(!visited[x]){
						visited[x]=true;
						st.push(x);
					}
				}
			}
		}
	}
	
};

int main(){
	Graph g(6);
	g.addEdge(0,1); 
    g.addEdge(0,2); 
    g.addEdge(1,3); 
    g.addEdge(1,4); 
    g.addEdge(2,3); 
    g.addEdge(4,3);
	g.addEdge(4,5);
	g.addEdge(3,5); 
    cout<<"Bfs\n";
	g.bfs(0);
    cout<<"Dfs\n";
    g.dfs(2);
}

