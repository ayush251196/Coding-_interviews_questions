//To find zig zag traversal of the binary tree
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case

void zigZagTraversal(Node* root)
{
    if(!root)
        return;
    stack<Node*> st1,st2;
    st1.push(root);
   while(!st1.empty() or !st2.empty()){
        
       while(!st1.empty()){
           Node* t=st1.top();
           cout<<t->data<<" ";
           st1.pop();
           if(t->left)
            st2.push(t->left);
           if(t->right)
            st2.push(t->right);
       }
       while(!st2.empty()){
           Node* t=st2.top();
           cout<<t->data<<" ";
           st2.pop();
           if(t->right)
            st1.push(t->right);
           if(t->left)
            st1.push(t->left);
       }
       
    }cout<<endl;
}
