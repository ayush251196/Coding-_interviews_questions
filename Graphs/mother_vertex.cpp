//The mother_vertex is the vertex through which there exist atleast one path to every remaining vertices.
#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
		int V;
		vector<int> *adj;
		Graph(int v){
			V=v;
		}
		add_edge(int x,int y){
			adj[x].push_back(y);
		}
		bfs(int s,vector<bool> &visited){
			visited[s]=true;
			for(auto x:adj[s]){
				if(!visited[x]){
					bfs(x,visited);
				}
			}
		}
		void find_mother_vertex(){
			// If the mother vertex exists then it should take the largest time for dfs or it should be the last traversed
			// vertex in dfs
			vector<bool> visited(V,false);
			int v;
			//modified dfs for disconnected graph also..
			for(int i=0;i<V;i++){
				if(!visited[i]){
					bfs(i,visited);
					v=i;
				}
			}
			//-----------------------------------------
			
			for(int i=0;i<V;i++){
				visited[i]=false;
			}
			
			//If v is mother vertex then dfs from v should cover all the remaining vertices
			bfs(v,visited);
			for(int i=0;i<V;i++){
				if(visited[i]==false){
					cout<<"-1";
					return;
				}	
			}
			cout<<v<<endl;
			
		}
};
int main(){
	
}
