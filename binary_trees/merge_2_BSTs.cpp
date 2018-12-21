//Merge 2 BST's
//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
void fill_v(Node* root,vector<int> &v){
    if(!root)
        return;
    fill_v(root->left,v);
    v.push_back(root->data);
    fill_v(root->right,v);
}
void merge(Node *root1, Node *root2)
{
   //Your code here
   vector<int> v1,v2;
   fill_v(root1,v1);
   fill_v(root2,v2);
   int i=0,j=0;
   while(i<v1.size() and j<v2.size()){
      if(v1[i]<=v2[j]){
          cout<<v1[i]<<" ";
          i++;
      }else{
          cout<<v2[j]<<" ";
          j++;
      }
   }
   if(i==v1.size()){
       while(j!=v2.size()){
           cout<<v2[j]<<" ";
           j++;
       }
   }else if(j==v2.size()){
       while(i!=v1.size()){
           cout<<v1[i]<<" ";
           i++;
       }
   }
}
