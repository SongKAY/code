class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        map<int,map<int,int>> dp;
        int result = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i] - A[j];
                if(dp[j][diff]!=0)
                    dp[i][diff] = max(dp[j][diff]+1,dp[i][diff]);
                if(dp[i][diff]==0)
                    dp[i][diff] = 2;
                result = max(result,dp[i][diff]);
            }
        }
        return result;
    }
};
