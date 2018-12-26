//Given a Binary Tree, print the diagnol traversal of the binary tree.
//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

//helper method
void print(Node* root,vector<Node*> vec){
    vector<Node*> v;
    if(vec.size()==0){
        return;
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]->data<<" ";
        Node* temp=vec[i]->left;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->right;
        }
    }
    print(root,v);
}
//call this method
void diagonalPrint(Node *root)
{  
  vector<Node*> v;
  while(root!=NULL){
      v.push_back(root);
      root=root->right;
  }
  print(root,v);
   
}
