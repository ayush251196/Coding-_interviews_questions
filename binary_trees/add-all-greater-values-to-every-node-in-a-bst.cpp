//Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node.
//https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1

/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  modifies the root of the bst */
int sum(Node* root){
    if(!root){
        return 0;
    }
   int s=0;
   queue<Node*> q;
   q.push(root);
   while(1){
       int size=q.size();
       if(!size){
           break;
       }
       while(size--){
           Node* f=q.front();
           q.pop();
           s+=f->data;
           if(f->left){
               q.push(f->left);
           }if(f->right){
               q.push(f->right);
           }
       }
   }return s;
}
void perform(Node* root,int* s){
    if(!root){
        return;
    }
    int ts=root->data;
    perform(root->left,s);
     root->data=(*s);
    *s-=ts;
    perform(root->right,s);
}
void modify(Node **root)
{   Node* temp=*root;
    int s=sum(temp);
    perform(temp,&s);
    *root=temp;
}
