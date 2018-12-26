//Boundary traversal of binary trees
//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void printBoundaryLeft(Node* root){
    if(!root){
        return ;
    }
    if(root->left){
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}
void printBoundaryRight(Node* root){
    if(!root){
        return ;
    }
    if(root->right){
        printBoundaryRight(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printBoundaryRight(root->left);
        cout<<root->data<<" ";
    }
}
void printLeaves(Node* root){
    if(!root){
        return;
    }
    if(!root->left and !root->right){
        cout<<root->data<<" ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printBoundary(Node *root)
{
     cout<<root->data<<" ";
        printBoundaryLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printBoundaryRight(root->right);
     
}
