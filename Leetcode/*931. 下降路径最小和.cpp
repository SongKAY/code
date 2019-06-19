class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
            dp[0][i] = A[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = dp[i-1][j] + A[i][j];
                if(j+1<m)
                    dp[i][j] = min(dp[i-1][j+1]+A[i][j],dp[i][j]);
                if(j-1>=0)
                    dp[i][j] = min(dp[i-1][j-1]+A[i][j],dp[i][j]);
            }
        }
        int result = dp[n-1][0];
        for(int i=1;i<m;i++){
            result = min(result,dp[n-1][i]);
        }
        return result;
    }
};
