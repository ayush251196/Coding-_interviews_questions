/*Pros
1 Searching an edge taking log(v) time
2 Edges can be added in constant time

Cons
1 In the set implementation we can't have parallel edges

However adjacency matrix is most optimised for edge search but the space complexity is the issue and also is costly for 
implementing bfs and dfs since it is not quick to get adjacent nodes of a node.
*/

#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
		int V;
		unordered_set<int> *adj;
		Graph(int V){
			this->V=V;
			adj=new unordered_set<int>[V];
		}
		bool search_edge(int x,int y){
			if(adj[x].find(y)!=adj[x].end()){
				return true;
			}return false;
		}
		void add_edge(int x,int y){
			adj[x].insert(y);
			adj[y].insert(x);
		}
		void bfs(int s){
			queue<int> q;
			vector<bool> visited(V,false);
			q.push(s);
			visited[s]=true;
			while(1){
				int size=q.size();
				if(!size)
					break;
				while(size--){
					int s=q.front();
					cout<<s<<" ";
					q.pop();
					for(auto x:adj[s]){
						if(!visited[x]){
							visited[x]=true;
							q.push(x);
						}
					}
				}
			}
		}
};
