class Solution {
public:
    set<vector<int>> result;
    void dfs(int k,vector<int> nums,vector<int> temp){
        if(temp.size()>=2)
            result.insert(temp);
        for(int i=k;i<nums.size();i++){
            if(!temp.empty()&&temp.back()>nums[i])
                continue;
            temp.push_back(nums[i]);
            dfs(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(0,nums,temp);
        return vector<vector<int>> (result.begin(),result.end());
    }
};
