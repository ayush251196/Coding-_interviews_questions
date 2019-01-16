//To find the length of longest path between any 2 vertices of a undirected graph having no cycles between any 2 vertices.
#include<iostream>
#include<vector>
using namespace std;
class Graph{
	public:
		int V;
		list<pair<int,int>> *adj;
		Graph(int V){
			this->V=V;
			adj=new list<pair<int,int>>[V];
		}
		void addEdge(int x,int y,int data){
			adj[x].push_back(make_pair(y,data));
			adj[y].push_back(make_pair(x,data));
		}
		void dfs(int v,vector<int> &visited,int prev_len,int &max_len){
			visited[v]=true;
			int curr_len=0;
			for(auto p:adj[v]){
				if(!visited[p.first]){
					curr_len=prev_len+p.second;
					dfs(p.first,visited,curr_len,max_len);
				}
				max_len=max(max_len,curr_len);
				curr_len=0;
			}
			
		}
		int longestPathCalc(){
			int max_len=INT_MIN;
			for(int i=0;i<V;i++){
				vector<bool> visited(V,false);
				dfs(i,visited,0,max_len);
			}
			return max_len;
		}
};
int main(){
	Graph g(6);
	g.addEdge(0,1,3);
	g.addEdge(1,5,2);
	g.addEdge(1,2,4);
	g.addEdge(5,3,6);
	g.addEdge(5,4,5);
	cout<<g.longestPathCalc();
	
}
