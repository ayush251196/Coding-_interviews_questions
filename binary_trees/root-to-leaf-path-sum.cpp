//Has a root to leaf path sum.
//https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
bool hasPathSum(Node *root, int sum)
{
   if(!root){
       return false;
   }
   if(sum-root->data<0){
       return false;
   }
   if(sum-root->data==0){
       if(!root->left and !root->right){
           return true;
       }return false;
   }
   return hasPathSum(root->left,sum-root->data) or hasPathSum(root->right,sum-root->data);
}
