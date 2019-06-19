class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = n;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                result += 1;
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<i-1;j++){
                if(s[i]==s[j]&&dp[j+1][i-1]){
                    dp[j][i] = 1;
                    result += 1;
                }
            }
        }

        return result;
    }
};
