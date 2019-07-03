class Solution {
public:
    vector<string> result;
    void dfs(int left,int right,string temp){
        if(!left&&!right){
            result.push_back(temp);
            return;
        }
        if(left>right)
            return;
        if(left>=1)
            dfs(left-1,right,temp+'(');
        if(right>=1)
            dfs(left,right-1,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,n,"");
        return result;
    }
};
