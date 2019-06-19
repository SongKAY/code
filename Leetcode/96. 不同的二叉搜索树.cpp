class Solution {
public:
    int numTrees(int n) {
        if(n<3)
            if(n<2)
                return 1;
            else
                return 2;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i] += dp[i-j-1] * dp[j];
            }
        }
        return dp[n];
    }
};
