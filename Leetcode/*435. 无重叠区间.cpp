class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1)
            return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> dp(n+1,0);
        dp[0] = 1;
        int result = 0;
        for(int i=0;i<n;i++){
            int x = intervals[i][0];
            for(int j=0;j<i;j++){
                int y = intervals[j][1];
                if(x>=y)
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        dp[n-1] = max(dp[n-1],1);
        return n - dp[n-1];
    }
};
