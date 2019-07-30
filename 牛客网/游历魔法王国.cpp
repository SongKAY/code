#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int dfs(vector<int> temp){
    int result = 0;
    int n = temp.size();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        dp[i] = dp[temp[i-1]] + 1;
        result = max(dp[i],result);
    }
    return result;
}

int main(){
    int n ,L;
    while(cin>>n>>L){
        vector<int> temp(n,0);
        for(int i=0;i<n-1;i++)
            scanf("%d",&temp[i]);
        int maxlength = dfs(temp);
        if(maxlength-1>=L)
            cout<<L+1<<endl;
        else if(maxlength-1<L&&(n - maxlength + 1) * 2 + maxlength - 1 >= L)
            cout<<(L-maxlength+ 1) / 2 + maxlength <<endl;
        else{
            cout<<n<<endl;
        }
    }
    return 0;
}
