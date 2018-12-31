//Two trees are identical datawise and structure wise
//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1


bool isIdentical(Node* root1,Node* root2){
	if(!root1 and !root2){
		return true;
	}
	if(root1 and root2 and root1->data==root2->data){
		return isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);	
	}
	return false;
}

