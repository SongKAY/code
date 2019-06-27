class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& candidates, vector<int> temp, int pos, int sum, int target){
        if(sum==target){
            result.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=pos;i<candidates.size()&&candidates[i]<=target;i++){
            if(i>pos&&candidates[i-1]==candidates[i])
                continue;
            temp.push_back(candidates[i]);
            dfs(candidates,temp,i+1,sum+candidates[i],target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return result;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        dfs(candidates,temp,0,0,target);
        return result;
    }
};
