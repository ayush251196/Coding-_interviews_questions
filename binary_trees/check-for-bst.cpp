//Given a binary tree, return true if it is BST, else false.
//https://practice.geeksforgeeks.org/problems/check-for-bst/1

struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
bool inorder(Node* root,Node* &prev){
    if(!root){
        return true;
    }
    
    if(inorder(root->left,prev)){
        if(prev and prev->data>root->data)
            return false;
        prev=root;
        return inorder(root->right,prev);   
    }
}
bool isBST(Node* root) {
    Node* prev=NULL;
    return inorder(root,prev);
}

