class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> nums,vector<int> temp,vector<int> flag){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(flag[i])
                continue;
            temp.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums,temp,flag);
            temp.pop_back();
            flag[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return result;
        int n = nums.size();
        vector<int> flag(n,0);
        vector<int> temp;
        dfs(nums,temp,flag);
        return result;
    }
};
