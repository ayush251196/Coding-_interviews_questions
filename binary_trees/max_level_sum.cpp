//To find the maximum level sum
//https://practice.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */
int maxLevelSum(Node * root)
{
   queue<Node*> q;
   q.push(root);
   int mx=INT_MIN;
   while(1){
        int size=q.size();
        if(!size)
            break;
        int sum=0;
        while(size--){
            Node* front=q.front();
            q.pop();
            sum+=front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        mx=max(mx,sum);
   }
   return mx;
}

