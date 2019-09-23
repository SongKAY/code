class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> candidates,vector<int> temp,int target,int t,int sum){
        if(sum==target)
            result.push_back(temp);
        if(sum>target)
            return;
        for(int i=t;i<candidates.size();i++){
            if(i>t&&candidates[i]==candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            dfs(candidates,temp,target,i+1,sum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,temp,target,0,0);
        return result;
    }
};
