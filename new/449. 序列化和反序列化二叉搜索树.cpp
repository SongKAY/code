    string serialize(TreeNode* root) {
        if(root == nullptr) return {};
        string str;
        queue<TreeNode*> queue;     //层序遍历 辅助队列
        queue.push(root);
        
        while(!queue.empty()){
            int count = queue.size();
            while(count--){
                TreeNode* node = queue.front();
                queue.pop();
                if(node == nullptr)   //#存储空节点
                    str += "#";
                else{
                    str += to_string(node->val) + "!"; //存储节点值 !分割
                    queue.push(node->left);
                    queue.push(node->right);
                }
            }
        }
        
        return str;
    }

 TreeNode* deserialize(string data) {
        if(data.empty())    return NULL;
        int i =0, j=0;
        while(j<data.size() && data[++j]!='!') ;    // [i, j) 存储节点
        TreeNode* head = new TreeNode(stoi(data.substr(i, j-i)) );
        
        queue<TreeNode*> queue;
        queue.push(head);
        
        while(i < data.size()){
            TreeNode* node = queue.front();
            queue.pop();
            if(node == NULL)    continue;
            // 左节点
            i = ++j;
            if(i >= data.size())    break;
            if(data[i] == '#')
                node->left = nullptr;
            else{
                while(j<data.size() && data[++j] != '!');
                node->left = new TreeNode(stoi(data.substr(i, j-i)) );
            }
            queue.push(node->left);
            // 右节点
            i = ++j;
            if(i >= data.size())    break;
            if(data[i] == '#')
                node->right = nullptr;
            else{
                while(j<data.size() && data[++j] != '!');
                node->right = new TreeNode(stoi(data.substr(i, j-i)) );
            }
            queue.push(node->right);
        }
        
        return head;
    }
   };
