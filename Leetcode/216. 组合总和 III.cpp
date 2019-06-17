class Solution {
public:
    vector<vector<int>> result;
    void dfs(int k, int t,int n,int sum,vector<int> temp){
        if(temp.size()>t)
            return;
        if(k==10){
            if(temp.size()==t&&sum==n){
                result.push_back(temp);
            }
            return;
        }
        dfs(k+1,t,n,sum,temp);
        temp.push_back(k);
        dfs(k+1,t,n,sum+k,temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        dfs(1,k,n,0,temp);
        return result;
    }
};
