class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.empty())
            return 0;
        int n = A.size();
        int result = 0;
        map<int,map<int,int>> dp;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];
                if(dp[j][diff])
                    dp[i][diff] = max(dp[j][diff]+1,dp[i][diff]);
                if(dp[i][diff]==0)
                    dp[i][diff] = 2;
                result = max(result,dp[i][diff]);
            }
        }
        return result;
    }
};
