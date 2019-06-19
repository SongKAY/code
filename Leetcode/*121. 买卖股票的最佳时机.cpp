class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(prices[j]<prices[i]){
                    // dp[i] = max(dp[i],prices[i]-prices[j]);
                    result = max(prices[i]-prices[j],result);
                }
            }
        }
        return result;
    }
};
