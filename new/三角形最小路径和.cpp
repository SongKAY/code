class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[n-1][i] = triangle[n-1][i];
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<=j;i++){
                dp[j][i] = min(dp[j+1][i+1] + triangle[j][i],dp[j+1][i] + triangle[j][i]);
            }
        }   
        return dp[0][0];
    }
};
