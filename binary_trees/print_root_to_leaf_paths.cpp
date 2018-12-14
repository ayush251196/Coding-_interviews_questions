//Given a Binary Tree of size N, your task is to complete the function printPaths() that prints all the possible paths from root node to the all the leaf node's of //the binary tree.

void root_to_leaf_paths(Node* root){

	String path="";
	

}
void print(Node* root,String path){
	if(root){
	
		if(!root->left and !root->right){
			cout<<""+path+to_string(root->data)<<" "<"#";
			return;
		}
		
		print(root->left,path+to_string(root->data);
		print(root->right,path+to_string(root->data);
	
	}	

}
