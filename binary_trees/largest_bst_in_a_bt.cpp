//Given a binary tree, Your task is to complete the function largestBst that returns the size of the largest subtree which is also a Binary Search Tree (BST). 
//If the complete Binary Tree is BST, then return the size of whole tree.
//https://practice.geeksforgeeks.org/problems/largest-bst/1

int lB(Node* root,Node*parent,unordered_map<Node*,int> &v){
    if(!root){
        if(!parent){
            return 0;
        }
        else if(!parent->left){
            return INT_MIN;
        }return INT_MAX;
    }
    if(!root->left  and !root->right){
        v[root]=1;
        return root->data;
    }
    int rld=lB(root->left,root,v);
    int rrd=lB(root->right,root,v);
    if(root->data>rld and root->data<rrd){
        int rlc=0,rrc=0;
        if(root->left)
            rlc=v[root->left];
        if(root->right)
            rrc=v[root->right];
        v[root]=rlc+rrc+1;
        if(parent and parent->left==root){
            if(root->right)
                return root->right->data;
            return root->data;
        }
        if(parent and parent->right==root){
            if(root->left)
                return root->left->data;
            return root->data;
        }
    }
    else{
        v[root]=1;
        if(parent and parent->left==root){
            return INT_MAX;
        }return INT_MIN;
    }
    
    
}
int largestBst(Node *root)
{
	//Your code here
	unordered_map<Node*,int> v;
	lB(root,NULL,v);
	int mx=INT_MIN;
	if(v.size()==0){
	    return 0;
	}
	for(auto i=v.begin();i!=v.end();i++){
	    mx=max(mx,i->second);
	}
	return mx;
}
