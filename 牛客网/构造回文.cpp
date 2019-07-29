/*两个字符串(正向和反向)算最长公共子序列*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        int n = s.length();
        string str = s;
        reverse(str.begin(),str.end());
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int i=0;i<=n;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j] = max(dp[i-1][j-1] + 1,dp[i][j]);
                }
                else{
                    dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }
        cout<<n - dp[n][n]<<endl;
    }
    return 0;
}
