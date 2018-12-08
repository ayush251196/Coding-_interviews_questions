//To print all nodes that dont have sibling
//https://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/
//User function Template for C++
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Prints the nodes having no siblings.  */
void printSibling(Node* root)
{   
    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while(1){
        int size=q.size();
        if(!size)
            break;
        while(size--){
            Node* top=q.front();
            q.pop();
            if(top->left and !top->right){
                v.push_back(top->left->data);
                q.push(top->left);
            }
            if(top->right and !top->left){
                v.push_back(top->right->data);
                q.push(top->right);
            }else if(top->left and top->right){
                q.push(top->left);
                q.push(top->right);
            }
        }
    }
    if(!v.size()){
        cout<<"-1"<<" ";
    }else{
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
}
