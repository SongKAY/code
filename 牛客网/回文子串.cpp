#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int cnt = n;
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            if(i+1<n&&s[i]==s[i+1]){
                cnt ++;
                dp[i][i+1] = 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j]&&(i-1>=j+1&&dp[j+1][i-1])){
                    cnt ++;
                    dp[j][i] = 1;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
