class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())
            return 0;
        int n = cost.size();
        if(n==1)
            return cost[0];
        if(n==2)
            return cost[1];
        cost.push_back(0);
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return dp[n];
    }
};
