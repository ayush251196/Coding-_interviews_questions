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
		}
		int dfs(int s,int des){
			queue<int> q;
			vector<bool> visited(V,false);
			q.push(s);
			vector<int> distances(V,-1);
			distances[s]=0;
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
						}
						if(x==des){
							return distances[x];
						}
					}
				}
			}
			return -1;
		}
};
int main(){
	Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 4); 
    g.addEdge(2, 1); 
    g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(3,1);
	g.addEdge(4,1); 
	g.addEdge(5,3);
	cout<<g.dfs(3,0);
}
