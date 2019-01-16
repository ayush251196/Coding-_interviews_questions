#include<iostream>
#include<vector>
using namespace std;
class Graph{
	public:
		int V;
		int countPaths;
		vector<int> *adj;
		Graph(int v){
			V=v;
			adj=new vector<int>[V];
			countPaths=0;
		}
		void addEdge(int x,int y){
			adj[x].push_back(y);
		}
		void find_path(int s,int v,int des,vector<int> &vstd){
			if(vstd[v]){
				return;
			}
			if(v==des and s!=des){
				countPaths++;
				return;
			}
			
			for(auto x:adj[v]){
					vstd[v]=1;
					find_path(s,x,des,vstd);
			}
			vstd[v]=0;
			
		}
		void calc_paths(int s,int des){
			vector<int> vstd(V,0);
			find_path(s,s,des,vstd);
			cout<<countPaths<<endl;
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
    g.calc_paths(0,1);
}

