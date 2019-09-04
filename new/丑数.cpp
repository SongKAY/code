class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1)
            return n;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int p1=1;
        int p2=1;
        int p3=1;
        for(int i=2;i<=n;i++){
            int minx = min(dp[p1]*2,dp[p2]*3);
            minx = min(minx,dp[p3]*5);
            dp[i] = minx;
            if(minx==dp[p1]*2)
                p1 ++;
            if(minx==dp[p2]*3)
                p2 ++;
            if((minx==dp[p3]*5))
                p3 ++;
        }
        return dp[n];
    }
};
