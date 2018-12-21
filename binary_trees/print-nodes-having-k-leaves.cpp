//Print nodes having k leaves in its rooted subtree
//https://practice.geeksforgeeks.org/problems/print-nodes-having-k-leaves/1

/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};*/
/*You are required to complete below method */
void populate_map(Node* root,Node* parent,unordered_map<Node*,int> &m){
    
    if(!root)
        return;
        
    if(!root->left and !root->right and parent!=NULL){
        m[parent]+=1;
        return;
    }
        
    if(m.find(root)==m.end())
        m[root]=0;
    
    populate_map(root->left,root,m);
    populate_map(root->right,root,m);
    if(parent!=NULL)
        m[parent]+=m[root];
        
}
void btWithKleaves(Node *ptr, int k)
{  unordered_map<Node*,int > m;
   populate_map(ptr,NULL,m);
   int flag=0;
   vector<int> results;
  // cout<<m.size();
   for(auto i=m.begin();i!=m.end();i++){
       if(i->second==k){
            flag=1;
            results.push_back(i->first->data);
       }
    }
    if(!flag){
        cout<<-1<<endl;
        return;
    }
    else{
        sort(results.begin(),results.end());
         for(int i=0;i<results.size();i++){
           cout<<results[i]<<" ";
         }
    }
    cout<<endl;
}
   

