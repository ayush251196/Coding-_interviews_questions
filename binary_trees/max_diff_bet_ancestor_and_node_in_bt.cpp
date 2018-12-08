//This function returns max difference between a node and its ancestor (ancestor - node )
//https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
int maxDiff(Node* root)
{   queue<Node*> q;
    int max_diff=INT_MIN;
    unordered_map<Node*,int> mp;
    assign_min(root,mp);
    q.push(root);
    while(1){
        int size=q.size();
        if(!size){
            break;
        }
        while(size--){
            Node* n=q.front();
            q.pop();
            max_diff=max(max_diff,n->data-mp[n]);
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
    }
    return max_diff;
}
