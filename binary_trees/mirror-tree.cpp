//Convert tree to its mirror form
//https://practice.geeksforgeeks.org/problems/mirror-tree/1

struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
     if(!node){
         return;
     }
     mirror(node->left);
     mirror(node->right);
     swap(node->left,node->right);
}
