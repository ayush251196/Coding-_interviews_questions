//Write a program to delete  binary tree

void delete(Node* root){
	if(!root){
		return ;
	}
	delete(root->left);
	delete(root->right);
	free(root);
	
}
