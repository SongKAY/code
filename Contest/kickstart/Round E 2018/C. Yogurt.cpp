#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;


int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n,k;
        scanf("%d %d",&n,&k);
        vector<int> v;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int result = 0;
        int day = 1;
        int cnt = 0;
        for(int i=0;i<v.size();){
            if(cnt<k){
                if(v[i]>=day){
                    cnt++;
                    result++;
                    i++;
                }
                else{
                    i++;
                }
            }
            else{
                cnt = 0;
                day++;
                while(i<v.size()&&v[i]<day)
                    i++;
            }
        }
        printf("Case #%d: %d\n",tt,result);
    }
    return 0;
}
