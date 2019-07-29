#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        vector<int> dp(n+1,999999);
        vector<int> l{1,1};
        vector<int> price{6,8};
        dp[0] = 0;
        for(int i=0;i<2;i++){
            for(int j=price[i];j<=n;j++){
                dp[j] = min(dp[j],dp[j-price[i]] + 1);
            }
        }
        if(dp[n]==999999)
            cout<<-1<<endl;
        else
            cout<<dp[n]<<endl;
    }
    return 0;
}
