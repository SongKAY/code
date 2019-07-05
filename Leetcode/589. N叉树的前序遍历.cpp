/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        if(root==NULL)
            return result;
        s.push(root);
        while(!s.empty()){
            Node *t = s.top();
            s.pop();
            result.push_back(t->val);
            for(int i=t->children.size()-1;i>=0;i--)
                s.push(t->children[i]);
        }
        return result;
    }
};
