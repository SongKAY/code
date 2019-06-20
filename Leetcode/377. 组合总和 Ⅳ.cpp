class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long dp[target+1]={0};
        dp[0]=1;
        sort(nums.begin(), nums.end());
        for(int i=1;i<=target;i++){
            for(int num:nums){
                if(i>=num){
                    dp[i]+=dp[i-num]%INT_MAX;
                }
            }
        }
        return dp[target];
    }
};
