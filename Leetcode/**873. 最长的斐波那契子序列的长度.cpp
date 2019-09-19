class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int maxlen = 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[A[i]] = i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                dp[j][i] = 2;
                if(A[i]-A[j]<A[i]&&m.find(A[i]-A[j])!=m.end()){
                    int k = m[A[i]-A[j]];
                    dp[j][i] = max(dp[k][j]+1,dp[j][i]);
                }
                maxlen = max(dp[j][i],maxlen);
            }
        }
        return maxlen>2?maxlen:0;
    }
};
