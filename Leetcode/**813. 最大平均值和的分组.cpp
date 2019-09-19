class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.empty())
            return 0.0;
        int n = A.size();
        vector<vector<double>> dp(n+1,vector<double>(K+1,0));
        vector<double> sum(n+1,0);
        for(int i=1;i<=n;i++)
            sum[i] = sum[i-1] + A[i-1];
        for(int i=1;i<=n;i++)
            dp[i][1] = sum[i] / i;
        for(int i=1;i<=n;i++){
            for(int k=2;k<=i&&k<=K;k++){
                for(int j=0;j<i;j++){
                    dp[i][k] = max(dp[i][k],dp[j][k-1]+(sum[i]-sum[j])/double(i-j));
                }
            }
        }
        return dp[n][K];
    }
};
