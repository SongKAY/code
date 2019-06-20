class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n==0||n==1)
            return n;
        vector<int> dp(n+1,1);
        sort(pairs.begin(),pairs.end(),cmp);
        int result = 1;
        for(int i=1;i<n;i++){
            int s = pairs[i][0];
            for(int j=0;j<i;j++){
                int e = pairs[j][1];
                if(e<s){
                    dp[i] = max(dp[i],dp[j]+1);
                    result = max(result,dp[i]);
                }
            }
        }
        return result;
    }
};
