//Print the top view in level order fashion
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
void top_view(Node* root){

	unordered_set<int> s;
	queue<pair<Node* ,int>> q;
	q.push(make_pair(root,0));
	while(1){
		int size=q.size();
		if(!size)
			break;
		while(size--){
			auto front=q.front();
			q.pop();
			if(s.find(front.second)==s.end()){
				cout<<front.first->data<<" ";
				s.insert(front.second);
			}
			if(front.first->left){
				q.push(make_pair(front.first->left,front.second-1));	
			}if(front.first->second){
				q.push(make_pair(front.first->right,front.second+1));
			}
		}
	
	}

}
