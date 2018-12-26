//Serialize and Deserialize a Binary Tree
//https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
Node* dS(Node* root,vector<int> &A,int &i){
    
    if(A[i]==-1){
        return NULL;
    }
    
    root=newNode(A[i]);
    i++;
    root->left=dS(root->left,A,i);
    i++;
    root->right=dS(root->right,A,i);
    return root;
}
void serialize(Node *root,vector<int> &A)
{
    if(!root){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{   Node* root;
    int i=0;
    return dS(root,A,i);
}

