#include<iostream>
using namespace std;
class Graph{
	public:
		int V;
		vector<int> *adj;
		Graph(int V){
			this->V=V;
			adj=new vector<int>[V];
		}
		addEdge(int x,int y){
			adj[x].push_back(y);
		}
		bool dfsUTIL(int v,vector<bool> &visited,vector<bool> &inrecStack){
			visited[v]=true;
			inrecStack[v]=true;
			for(auto x:adj[v]){
				if(!visited[x] and dfsUTIL(x,visited,inrecStack)){
					return true;					
				}if(inrecStack[x]){
					return true;
				}
			}
			inrecStack[v]=false;
			return false;

		}
		bool isCyclic(){
			vector<bool> visited(V,false);
			vector<bool> inrecStack(V,false);
			for(int i=0;i<V;i++){
				if(dfsUTIL(i,visited,inrecStack)){
					return true;
				}
			}
			return false;
		}
};
int main(){
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
}
