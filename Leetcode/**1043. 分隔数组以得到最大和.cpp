class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if(A.empty())
            return 0;
        int n = A.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int curmax = -1;
            for(int j=1;j<=K&&i-j>=0;j++){
                curmax = max(A[i-j],curmax);
                dp[i] = max(dp[i],dp[i-j]+curmax*j);
            }
        }
        return dp[n];
    }
};
