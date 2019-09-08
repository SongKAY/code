//非递归
TreeNode *convert(TreeNode *root){
	if(root==NULL)
		return NULL;
	stack<TreeNode*> s;
	int flag= 0;
	TreeNode *p = root;
	TreeNode *pre = root;
	while(p||!s.empty()){
		while(p){
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		if(!flag){
			root = p;
			flag = 1;
			pre = root;
		}
		else{
			pre->right = p;
			p->left = pre;
			pre = p;
		}
		p = p->right;
	}
	return root;
}

//递归
TreeNode *p = NULL;
TreeNode *pre = NULL;

TreeNode *convert(TreeNode *root){
	conversub(root);
	return pre;
}

void *conversub(TreeNode *root){
	if(root==NULL)
		return;
	convert(root->left);
	if(p==NULL){
		p = root;
		pre = root;
	}
	else{
		p->right = root;
		root->left = p;
		p = root;
	}
	convert(root->right);
}
