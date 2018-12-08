//To print the binary tree in the vertical order
//https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
//A function that takes a root, a map and a d variable(stores horizontal distance of a node from root with sign)
int min_d=INT_MAX,max_d=INT_MIN;
void fill_map(Node* root,unordered_map<int,vector<int>> &mp,int d){
    if(!root){
        return ;
    }
    mp[d].push_back(root->data);
    min_d=min(d,min_d);
    max_d=max(d,max_d);
    fill_map(root->left,mp,d-1);
    fill_map(root->right,mp,d+1);
}
void verticalOrder(Node *root)
{
    unordered_map<int,vector<int> > mp;
    fill_map(root,mp,0);
    for(int i=min_d;i<=max_d;i++){
        auto v=mp[i];
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
    }
    min_d=INT_MAX;
    max_d=INT_MIN;
}
