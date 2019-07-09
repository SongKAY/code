class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> f(n+1,0);
        for(int i=1;i<=n;i++){
            int curmax = -1;
            for(int j=1;j<=K&&i-j>=0;j++){
                curmax = max(curmax,A[i-j]);
                f[i] = max(f[i],f[i-j]+curmax*j);
            }
        }
        return f[n];
    }
};
