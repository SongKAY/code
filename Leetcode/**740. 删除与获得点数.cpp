class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
            m[nums[i]] += 1;
        sort(nums.begin(),nums.end());
        int maxn = nums[nums.size()-1];
        vector<int> dp(maxn+1,0);
        dp[1] = m[1];
        int result = max(0,m[1]);
        for(int i=2;i<=maxn;i++){
            dp[i] = max(dp[i-1],dp[i-2]+m[i]*i);
            result = max(result,dp[i]);
        }
        return result;
    }
};
