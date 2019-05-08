#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int L;
        scanf("%d",&L);
        map<int,ll> employee;
        vector<int> v;
        for(int i=0;i<L;i++){
            ll n;
            int m;
            scanf("%lld %d",&n,&m);
            employee[m] = n;
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        int i = 0;
        ll pre = employee[v[i]];
        ll left = 0;
        int result = v[v.size()-1]+1;
        i++;
        for(;i<v.size();i++){
            ll cur = employee[v[i]] * v[i]; 
            left = (cur>=pre)?0:pre-cur;
            pre = employee[v[i]]+left;
        }
        while(result<pre){
            result ++;
        }
        printf("Case #%d: ",tt);
        cout<<result<<endl;
    }
    return 0;
}
