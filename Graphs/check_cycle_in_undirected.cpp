//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//Detect cycle in an undirected graph
//unordered_set is used as we assume here that there is not parallel edges so if any it will remove.
#include<iostream>
#include<vector>
using namespace std;
class Graph{
	public:
		int V;
		unordered_set<int> *adj;
		Graph(int V){
			this->V=V;
			adj=new unordered_set<int>[V];
		}
		addEdge(int x,int y){
			adj[x].insert(y);
			adj[y].insert(x);
		}
		bool dfsUTIL(int v,vector<bool> &visited,int parent){
			visited[v]=true;
			for(auto x:adj[v]){
				if(!visited[x]){
					if(dfsUTIL(x,visited,v)){
						return true;
					}
				}
				else if(x!=parent){
					return true;
				}
			}
			return false;
		}
		bool checkCycle(){
			vector<bool> visited(V,false);
			for(int i=0;i<V;i++){
				if(!visited[i]){
					if(dfsUTIL(i,visited,-1)){
						return true;
					}
				}
			}
			return false;
		}
};
