//lowest-common-ancestor-in-a-binary-tree in a single traversal
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report the presence 
    // by setting v1 or v2 as true and return root (Note that if a key 
    // is ancestor of other, then the ancestor key becomes LCA) 
    if (root->data == n1) 
    { 
        v1 = true; 
        return root; 
    } 
    if (root->data == n2) 
    { 
        v2 = true; 
        return root; 
    } 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2); 
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 
   
// This function returns LCA of n1 and n2 only if both n1 and n2 are present 
// in tree, otherwise returns NULL; 
Node *LCA(Node *root, int n1, int n2) 
{ 
    bool v1 = false, v2 = false; 
  
    Node *lca = findLCAUtil(root, n1, n2, v1, v2); 
    if(v1 and v2){
        return lca;
    }
    
    return NULL; 
} 
  
