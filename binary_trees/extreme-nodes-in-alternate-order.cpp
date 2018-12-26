//Given a binary tree, print nodes of extreme corners of each level but in alternate order.
//https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1

void printExtremeNodes(Node* root){
    queue<Node*>  q;
    q.push(root);
    int c=0;
    while(1){
        int size=q.size();
        int temp=size;
        if(!size)
            break;
        while(size--){
            Node* front=q.front();
            q.pop();
            if(temp==size+1)
                cout<<front->data<<" ";
            if(c%2==0){
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }else{
                if(front->right)
                    q.push(front->right);
                if(front->left)
                    q.push(front->left);
            }
        }
        c+=1;
    }
}

