//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
//Connect Nodes at Same Level
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
   queue<Node*> q;
   q.push(p);
   while(1){
       Node* prev=NULL;
       int size=q.size();
       if(!size){
           break;
       }
       while(size--){
           Node* f=q.front();
           q.pop();
           if(!prev){
               f->nextRight=NULL;
           }else{
               prev->nextRight=f;
               f->nextRight=NULL;
           }
           if(f->left){
               q.push(f->left);
           }if(f->right){
               q.push(f->right);
           }
           prev=f;
       }
   }
}

