class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1)
            return n;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int t1 = 1;
        int t2 = 1;
        int t3 = 1;
        for(int i=2;i<=n;i++){
            int minx = min(dp[t1]*2,dp[t2]*3);
            minx = min(minx,dp[t3]*5);
            if(minx == dp[t1]*2)
                t1 ++;
            if(minx == dp[t2]*3)
                t2 ++;
            if(minx==dp[t3]*5)
                t3 ++;
            dp[i] = minx;
        }
        return dp[n];
    }
};
