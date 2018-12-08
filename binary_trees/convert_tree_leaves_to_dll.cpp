//Convert tree leaves to doubly linked list
//https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
/*
struct Node{
	int data;
	Node *left,*right;
};
*/

Node *convertToDLL(Node *root,Node **head_ref)
{
    if(!root)
        return NULL ;
    
    if(!root->left and !root->right){
        if(!(*head_ref)){
            *head_ref=root;
            (*head_ref)->left=NULL;
            (*head_ref)->right=NULL;
        }
        else{
            (*head_ref)->left=root;
            root->right=*head_ref;
            root->left=NULL;
            *head_ref=root;
        }
        return root;
    }
    root->right=convertToDLL(root->right,head_ref);
    root->left=convertToDLL(root->left,head_ref);
    return root;
}

