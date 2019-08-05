#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void init(vector<long long>&dp){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=1000;i++){
        for(int j=0;pow(2,j)<=i;j++){
            dp[i] += dp[i-pow(2,j)];
            dp[i] %= 1000000003LL;
        }
        //cout<<i<<' '<<dp[i]<<endl;
    }
    return;
}

int main(){
    
    int n;
    cin>>n;
    vector<long long> dp(1001,0);
    init(dp);
    while(n--){
        int m;
        cin>>m;
        cout<<dp[m]<<endl;
    }
    return 0;
}
