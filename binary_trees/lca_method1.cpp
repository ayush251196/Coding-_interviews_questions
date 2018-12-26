//LCA method1
//by storing root to given nodes path and encountering the last common (before the first mismatch)
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
bool populate(Node* root,vector<Node*> &p,int n){
    if(!root){
        return false;
    }
    p.push_back(root);
    if(root->data==n){
        return true;
    }
    if(populate(root->left,p,n) or populate(root->right,p,n)){
        return true;
    }
    p.pop_back();
    return false;
    
}
Node * LCA(Node* root ,int n1 ,int n2 )
{
   vector<Node*> p1,p2;
   populate(root,p1,n1);
   populate(root,p2,n2);
   int i=0,j=0;
   while(i<p1.size() and j<p2.size() and p1[i]==p2[j]){
       i++;
       j++;
   }
   i--;
   return p1[i];
}
