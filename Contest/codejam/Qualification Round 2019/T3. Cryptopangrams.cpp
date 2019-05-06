####Test Set2 Runtime Error######
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;

ll gcd(ll n,ll m){
    if(m>n){
        ll temp = n;
        n = m;
        m = temp;
    }
    ll r=0;
    while(m){
        r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main(){
    
    int T;
    scanf("%d",&T);
    for(int epoch=1;epoch<=T;epoch++){
        int n,l;
        scanf("%d %d",&n,&l);
        vector<ll> plus;
        for(int i=0;i<l;i++){
            ll a;
            scanf("%lld",&a);
            plus.push_back(a);
        }
        map<ll,ll> m;
        vector<ll> result;
        int pos = -1;
        for(int i=0;i<plus.size()-1;i++){
            if(plus[i]!=plus[i+1]){
                pos = i;
                break;
            }
        }
        vector<ll> ans(l+1,0);
        if(pos==-1){
            for(int i=0;i<l+1;i++)
                ans[i] = sqrt(plus[0]);
        }
        else{
            ll t = gcd(plus[pos],plus[pos+1]);
            ans[pos+1] = t;
            for(int i=pos;i>=0;i--)
                ans[i] = plus[i] / ans[i+1];
            for(int i=pos+2;i<l+1;i++)
                ans[i] = plus[i-1] / ans[i-1];
        }
        vector<ll> temp = ans;
        sort(ans.begin(),ans.end());
        ll cnt = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=ans[i+1]){
                m[ans[i]] = cnt++;
            }
        }
        string str;
        for(int i=0;i<temp.size();i++)
            str += m[temp[i]] + 'A';
        printf("Case #%d: ",epoch);
        cout<<str<<endl;
    }
    return 0;
}
