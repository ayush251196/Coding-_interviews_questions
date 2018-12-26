//Given a Binary Tree,  print the bottom view from left to right.
//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
void preorder(Node* root,map<int,Node*> &mp,int d){
    if(!root){
        return;
    }
    mp[d]=root;
    preorder(root->left,mp,d-1);
    preorder(root->right,mp,d+1);
}
void bottomView(Node *root)
{       
    map<int,Node*> mp;
    preorder(root,mp,0);
    for(auto i=mp.begin();i!=mp.end();i++){
        cout<<i->second->data<<" ";
    }
}

