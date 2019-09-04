class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int result = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = 1;
                    result = max(result,dp[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'&&i-1>=0&&j-1>=0){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = min(dp[i-1][j-1],dp[i][j]) + 1;
                    result = max(dp[i][j],result);
                }
            }
        }
        return result * result;
    }
};
