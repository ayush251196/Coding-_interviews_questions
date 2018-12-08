//To calculate the vertical sum in a tree and print in space separated way
//https://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
int mx=INT_MIN,mnn=INT_MAX;
void fill_map(Node* root,map<int,int> &mp,int d){
    if(!root)
        return;
    if(mp.find(d)==mp.end()){
        mp[d]=root->data;
    }else{
        mp[d]+=root->data;
    }
    mx=max(mx,d);
    mnn=min(mnn,d);
    fill_map(root->left,mp,d-1);
    fill_map(root->right,mp,d+1);
    
}
void printVertical(Node *root)
{
    map<int,int> mp;
    fill_map(root,mp,0);
    for(int i=mnn;i<=mx;i++){
        cout<<mp[i]<<" ";
    }
    mx=INT_MIN;
    mnn=INT_MAX;
}
