#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INT_MAX 9999999

int main(){
    
    int n,w;
    cin>>n>>w;
    vector<int> price(n,0);
    vector<int> dp(w+1,INT_MAX);
    for(int i=0;i<n;i++)
        cin>>price[i];
    for(int i=0;i<n;i++){
        for(int j=w;j>=0;j--){
            if(price[i]>=j)
                dp[j] = min(dp[j],price[i]);
            else
                dp[j] = min(dp[j],dp[j-price[i]] + price[i]);
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}
