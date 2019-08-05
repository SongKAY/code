#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
#define INT_MAX 99999999

int main(){
    
    int n;
    while(cin>>n){
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        vector<int> a{3,5,7};
        for(int i=0;i<3;i++){
            for(int j=a[i];j<=n;j++){
                dp[j] = min(dp[j],dp[j-a[i]]+1);
            }
        }
        if(dp[n]==INT_MAX)
            cout<<"-1"<<endl;
        else
            cout<<dp[n]<<endl;
    }
    return 0;
}
