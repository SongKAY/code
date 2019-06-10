class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        if(sum%2!=0)
            return false;
        sum = sum/2;
        vector<int> dp(sum+1,0);
        for(int i=1;i<=sum;i++)
            dp[i] = -INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=sum;j>=nums[i];j--){
                dp[j] = max(dp[j-nums[i]] + nums[i],dp[j]);
            }
        }
        if(dp[sum]<0)
            return false;
        return true;
    }
};
