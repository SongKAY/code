class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        if(obstacleGrid[0][0]==1)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1)
                    continue;
                if(i-1>=0&&obstacleGrid[i-1][j]==0)
                    dp[i][j] += dp[i-1][j];
                if(j-1>=0&&obstacleGrid[i][j-1]==0)
                    dp[i][j] += dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
