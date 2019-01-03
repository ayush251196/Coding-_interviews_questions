#include<iostream>
#include<vector>
using namespace std;
class Graph{
	public:
		int V;
		vector<int> *adj;
		Graph(int V){
			this->V=V;
			adj=new vector<int>[V];
			
		}
		void addEdge(int x,int y){
			adj[x].push_back(y);
		}
		void dfs(vector<bool> &vstd,vector<vector<int>> &tc,int s,int v){
			tc[s][v]=1;
			for(auto x:adj[v]){
				if (tc[s][x] == 0 and !vstd[x]) 
					dfs(vstd,tc,s,x);
				else{
					if(vstd[x]){
						for(int i=0;i<V;i++){
							if(tc[x][i])
								tc[s][i]=tc[x][i];
						}	
					}
				}
			
			}
		}
	
	
		void transitive_closure(){
			vector<vector<int>> tc(V,vector<int>(V,0));
			vector<bool> v(V,false);
			for(int i=0;i<V;i++){
				v[i]=true;
				dfs(v,tc,i,i);
			}
			for (int i=0; i<V; i++) { 
		     	for (int j=0; j<V; j++) 
			        cout << tc[i][j] << " "; 
			    cout << endl; 
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
    cout << "Transitive closure matrix is \n"; 
    g.transitive_closure(); 
}
