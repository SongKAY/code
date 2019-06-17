//剪枝很关键
class Solution {
public:
    vector<vector<int>> result;
    void dfs(int t,int n,int k,vector<int> temp){
        if(n-t+1<k)
            return;
        if(t>n&&k!=0)
            return;
        if(k==0){
            result.push_back(temp);
            return;
        }
        temp.push_back(t);
        dfs(t+1,n,k-1,temp);
        temp.pop_back();
        dfs(t+1,n,k,temp);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(1,n,k,temp);
        return result;
    }
};
