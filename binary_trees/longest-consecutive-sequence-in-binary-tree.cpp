//Longest consecutive sequence in a binary tree where each node is path of length 1
//https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1
/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence
int mx=INT_MIN;
void lC(Node* root,unordered_map<Node*,int> &m,Node* parent){
    
    if(!root){
        return ;    
    }
    if(parent!=NULL and root->data==parent->data+1){
        m[root]=m[parent]+1;
    }
    else{
        m[root]=1;
    }
    lC(root->left,m,root);
    lC(root->right,m,root);
    
}

int longestConsecutive(Node* root)
{
    unordered_map<Node*,int> m;
    lC(root,m,NULL);
    for(auto i=m.begin();i!=m.end();i++){
        mx=max(i->second,mx);
    }
    int ans=mx;
    mx=INT_MIN;
    if(ans==1)
        return -1;
    return ans;
}

