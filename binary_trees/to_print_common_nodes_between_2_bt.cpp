//Given two Binary Search Trees, task is to complete the function printCommon, which print's the common nodes in them. In other words, find intersection of two BSTs.
//https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

bool search_tree(Node* root,int num){
    if(root){
        
        if(num>root->data){
            return search_tree(root->right,num);
        }if(num<root->data)
            return search_tree(root->left,num);
        if(num==root->data){
            return true;
        }
        
    }return false;
}

void populate(Node* root,Node* root1,set<int> &nodes){
    if(root){
        
        if(search_tree(root1,root->data)){
            nodes.insert(root->data);
        }    
        populate(root->left,root1,nodes);
        populate(root->right,root1,nodes);
    }
}


