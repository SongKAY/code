#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        vector<int> origin;
        vector<int> later;
        int N;
        scanf("%d",&N);
        vector<int> num(2*N,0);
        map<int,int> cnt;
        for(int i=0;i<2*N;i++){
            scanf("%d",&num[i]);
            cnt[num[i]] ++;
        }
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            if(!cnt[num[i]])
                continue;
            later.push_back(num[i]);
            cnt[num[i]] -= 1;
            int t = num[i] / 3 * 4;
            origin.push_back(t);
            cnt[t] -= 1;
            
        }
        printf("Case #%d: ",tt);
        for(int i=0;i<later.size()-1;i++){
            cout<<later[i]<<' ';
        }
        cout<<later[later.size()-1]<<endl;
    }
    return 0;
}
