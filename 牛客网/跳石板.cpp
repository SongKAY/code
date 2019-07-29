#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> init(int N){
    vector<int> v;
    for(int i=2;i<=sqrt(N);i++){
        if(N%i==0){
            v.push_back(i);
            if(N/i!=i)
                v.push_back(N/i);
        }
    }
    return v;
}

int main(){
    
    int N,M;
    while(cin>>N>>M){
        vector<int> dp(M+1,999999999);
        dp[N] = 0;
        for(int k=N;k<=M;k++){
            if(dp[k]==999999999)
                continue;
            vector<int> v = init(k);
            for(int i=0;i<v.size();i++){
                if(k+v[i]<=M)
                    dp[k+v[i]] = min(dp[k+v[i]],dp[k] + 1);
            }
        }
        if(dp[M]==999999999)
            cout<<-1<<endl;
        else
            cout<<dp[M]<<endl;
    }
    return 0;
}
