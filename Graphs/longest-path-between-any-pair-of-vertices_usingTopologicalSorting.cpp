//This method is used to find the length of longest path between a pair of vertices in the graph given that the graph is Directed and acyclic.
//The time complexity is O(V+E)
//Uses topological sorting.
#include<iostream>
#include<vector>
using namespace std;
class Graph{
	public:
		int V;
		list<pair<int,int>> *adj;
		Graph(int v){
			V=v;
			adj=new list<pair<int,int>>[V];
		}
		addEdge(int x,int y,int data){
			adj[x].push_back(y,data);
		}
		int* topological(){
			vector<int> degree(V,0);
			int *arr=new int[V];
			for(int i=0;i<V;i++){
				for(auto p:adj[i]){
					degree[p.first]++;
				}
			}
			queue<int> q;
			for(int i=0;i<V;i++){
				if(degree[i]==0){
					q.push(i);
				}
			}
			int i=0;
			while(!q.empty){
				int f=q.front();
				arr[i++]=f;
				q.pop();
				degree[f]=-1
				for(auto p:adj[f]){
					degree[p.first]--;
					if(degree[p.first]==0){
						q.push(p.first);
					}
				}
			}
			return arr;
		}
		int longest_path_length(){
			vector<int> dist(V,0);
			int *arr=topological();
			int maxdist=INT_MIN;
			for(int i=0;i<V;i++){
				for(auto p:adj[i]){
					dist[p.first]=max(dist[p.first],dist[i]+p.second);
					maxdist=max(dist[p.first],maxdist);
				}
			}
			return maxdist;
		}
};
int main(){
	
}
