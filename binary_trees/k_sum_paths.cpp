//A binary tree and a number k are given. Print the count of every path in the tree with sum of the nodes in the path as k.
//https://practice.geeksforgeeks.org/problems/k-sum-paths/1

int k_paths(Node* root,int k){
	if(!root){
		return 0;
	}
	return count_path_for_node(root,k,0)+k_paths(root->left,k)+k_paths(root->right,k);

}

int count_path_for_node(Node* root,int k,int sum){
	if(!root){
		return 0;
	}
	if(sum+root->data==k){
		return 1+count_path_for_node(root->left,k,sum+root->data)+count_path_for_node(root->right,k,sum+root->data);
	}
	return count_path_for_node(root->left,k,sum+root->data)+count_path_for_node(root->right,k,sum+root->data);
	
}

