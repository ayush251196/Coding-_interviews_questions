//Diameter of a binary tree
//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
/*
struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */
int height(Node* root){
    if(!root){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* root)
{
   if(!root){
       return 0;
   }
   int lheight=height(root->left);
   int rheight=height(root->right);
   
   return max(lheight+rheight+1,max(diameter(root->left),diameter(root->right)));
   
}
