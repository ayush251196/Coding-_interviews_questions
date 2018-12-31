//Find max and min element in binary tree
//https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

int findMax(struct node* root)
{   
    if(!root){
        return INT_MIN;
    }
    return max(max(findMax(root->left),findMax(root->right)),root->data);
}
// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if(!root){
        return INT_MAX;
    }
    return min(min(findMin(root->left),findMin(root->right)),root->data);
}
