class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        if(s.length()==0)
            return str;
        int n = s.length();
        int dp[n+1][n+1];
        int start = 0;
        int result = 0;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(j-i<2)
                    dp[i][j] = (s[i]==s[j]);
                else
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j]){
                    result = max(result,j-i+1);
                    if(result == j-i+1)
                        start = i;
                }
            }
        }
        return s.substr(start,result);
    }
};
