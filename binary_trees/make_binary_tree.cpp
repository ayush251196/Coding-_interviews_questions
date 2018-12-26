//Construct binary tree from a linked list
//https://practice.geeksforgeeks.org/problems/make-binary-tree/1

/*
The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
/*You are required to complete this method*/
TreeNode* makeNode(int data){
    TreeNode* tm=new TreeNode;
    tm->data=data;
    tm->right=tm->left=NULL;
    return tm;
}
void convert(node *head,TreeNode * &root){
  if(!head){
    root=NULL;
    return;
  }
  queue<TreeNode*> q;
  root=makeNode(head->data);
  q.push(root);
  while(1){
    int size=q.size();
    if(!size){
        break;
    }
    while(size--){
      TreeNode* f=q.front();
      q.pop();
      if(head){
        head=head->next;
        if(head){
          f->left=makeNode(head->data);
          q.push(f->left);
          head=head->next;
          if(head){
              f->right=makeNode(head->data);
              q.push(f->right);
          }
        }
      }
      
   }
      
  }
}

