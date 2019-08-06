#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    
    string temp;
    getline(cin,temp);
    istringstream scin(temp);
    int n;
    scin>>n;
    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++){
        scin>>dp[i];
    }
    vector<int> money(n+1,1);
    for(int i=1;i<n;i++){
        if(dp[i]>dp[i-1])
            money[i] = money[i-1] + 1;
    }
    for(int i=n-2;i>=0;i--){
        if(dp[i]>dp[i+1])
            money[i] = max(money[i+1]+1,money[i]);
    } 
    int result = 0;
    for(int i=0;i<n;i++){
        result += money[i];
    }
    cout<<result<<endl;
    return 0;
}
