#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dfs(int t,vector<vector<int>>dp, vector<int> color,int flag){
    if(color[t]&&color[t]==-flag)
        return false;
    if(color[t]==flag)
        return true;
    color[t] = flag;
    vector<int> temp = dp[t];
    if(temp.empty())
        return true;
    for(int i=0;i<temp.size();i++){
        if(color[temp[i]]&&color[temp[i]]==flag)
            return false;
        if(!dfs(temp[i],dp,color,-flag))
            return false;
    }
    return true;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        int flag = 0;
        vector<vector<int>> dp(n+1);
        while(m--){
            int a,b;
            cin>>a>>b;
            dp[a].push_back(b);
            dp[b].push_back(a);
        }
        vector<int> color(n+1,0);
        for(int i=1;i<=n;i++){
            if(!dp[i].empty()&&!color[i]){
                if(!dfs(i,dp,color,1)){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
