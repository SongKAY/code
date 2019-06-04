class Solution {
public:
    set<vector<int>> s;
    void dfs(int t,int n,vector<int>& nums,vector<int> temp){
        if(t==n){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        dfs(t+1,n,nums,temp);
        temp.push_back(nums[t]);
        dfs(t+1,n,nums,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        dfs(0,n,nums,temp);
        vector<vector<int>> result;
        set<vector<int>>::iterator it = s.begin();
        for(it;it!=s.end();it++){
            result.push_back(*it);
        }
        return result;
    }
};
