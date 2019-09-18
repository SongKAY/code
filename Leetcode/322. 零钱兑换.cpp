class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        for(int i=1;i<=amount;i++)
            dp[i] = 9999999;
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] = min(dp[j-coins[i]] + 1,dp[j]);
            }
        }
        if(dp[amount]==9999999)
            return -1;
        else
            return dp[amount];
    }
};
