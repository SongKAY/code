class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.empty())
            return 0;
        int n = days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int j = i;
            for(;j<=n;j++){
                if(days[i-1]+6<days[j-1])
                    break;
            }
            dp[j-1] = min(dp[j-1],dp[i-1]+costs[1]);
            j = i;
            for(;j<=n;j++){
                if(days[i-1]+29<days[j-1])
                    break;
            }
            dp[j-1] = min(dp[j-1],dp[i-1]+costs[2]);
            dp[i] = min(dp[i],dp[i-1]+costs[0]);
        }
        return dp[n];
    }
};
