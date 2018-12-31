//Reverse level order traversal of the binary tree
//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void reversePrint(Node *root)
{
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    s.push(root);
    while(1){
        int size=q.size();
        if(!size){
            break;
        }
        while(size--){
            Node* front=q.front();
            q.pop();
            if(front->right){
                q.push(front->right);
                s.push(front->right);
            }if(front->left){
                q.push(front->left);
                s.push(front->left);
            }
        }
    }
     while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
     }
}
