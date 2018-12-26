//Given a binary tree and two node values your task is to find the minimum distance between them.
//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/
Node* lca(Node* root,int a,int b){
    if(!root)
        return NULL;
    if(root->data==a or root->data==b){
        return root;
    }
    Node* r_lca=lca(root->left,a,b);
    Node* l_lca=lca(root->right,a,b);
    if(r_lca and l_lca){
        return root;
    }
    if(r_lca and !l_lca){
        return r_lca;
    }return l_lca;
}
int findDistance(Node* root,int a){
    if(!root){
        return -1;
    }
    int dist=-1;
    if(root->data==a or (dist=findDistance(root->left,a))>=0 or (dist=findDistance(root->right,a))>=0){
        return 1+dist;
    }
    return dist;
}
int findDist(Node* root, int a, int b)
{
    Node* lca_a_b=lca(root,a,b);
    int ld=findDistance(lca_a_b,a);
    int rd=findDistance(lca_a_b,b);
    return ld+rd;
    
}
