//Check if 2 binary trees are isomorphic or not
//https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 and !root2)
        return true;
    else if(root1 and !root2)
        return false;
    else if(!root1 and root2)
        return false;
    else if(root1->data!=root2->data)
        return false;

    return ((isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right))
    or (isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left)));
    
}
