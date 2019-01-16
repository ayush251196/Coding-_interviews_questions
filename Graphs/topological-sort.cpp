//Program for topological sorting(Kahn's algorithm)
//https://practice.geeksforgeeks.org/problems/topological-sort/1

int * topoSort(vector<int> graph[], int N)
{
   // Your code here
   vector<int> degree(N,0);
   for(int i=0;i<N;i++){
       for(auto x:graph[i]){
           degree[x]++;
       }
   }
  queue<int> q;
  for(int i=0;i<N;i++){
      if(degree[i]==0){
          q.push(i);
      }
  }
  int *res=new int[N];
  int i=0;
  while(!q.empty()){
      int top=q.front();
      q.pop();
      res[i++]=top;
      degree[top]=-1;
      for(auto x:graph[top]){
          degree[x]--;
          if(degree[x]==0){
              q.push(x);
          }
      }
  }
  return res;
}
