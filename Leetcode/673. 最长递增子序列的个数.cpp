class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> record(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    result = max(dp[i],result);
                }
            }
            int sum = 0;
            for(int j=0;j<i;j++){
                if(dp[j]==dp[i]-1&&nums[j]<nums[i])
                    sum += record[j];
                record[i] = max(record[i],sum);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==result)
                cnt += record[i];
        }
        return cnt;
    }
};
