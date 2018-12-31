//To find the size of the binary tree

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left;
     Node* right;
}; */
/* Computes the number of nodes in a tree. */
int getSize(Node* root)
{
   if(!root){
       return 0;
   }
   return 1+getSize(root->left)+getSize(root->right);
}
