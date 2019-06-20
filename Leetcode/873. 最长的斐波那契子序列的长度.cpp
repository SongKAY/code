class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        map<int,int> m;
        int result = 0;
        for(int i=0;i<n;i++)
            m[A[i]] = i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                dp[j][i] = 2;
                if(A[i]-A[j]<A[i]&&m.find(A[i]-A[j])!=m.end()){
                    int k = m[A[i]-A[j]];
                    dp[j][i] = max(dp[j][i],dp[k][j]+1);
                    result = max(result,dp[j][i]);
                }
            }
        }
        return (result>2)?result:0;
    }
};
