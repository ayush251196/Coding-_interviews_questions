//Construct tree from treeorder
//https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1
/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node* cT(int n,int pre[],char preLN[],int &i,Node* root){
    
    if(preLN[i]=='L'){
        Node* node=newNode(pre[i]);
        return node;
    }
    root=newNode(pre[i]);
    i++;
    root->left=cT(n,pre,preLN,i,root->left);
    i++;
    root->right=cT(n,pre,preLN,i,root->right);
    
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node* root;
    int i=0;
    return cT(n,pre,preLN,i,root);   
}

