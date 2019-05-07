#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int k;
        scanf("%d",&k);
        vector<int> nums(k+1,0);
        vector<int> f(k+1,0);
        for(int i=0;i<=k;i++){
            scanf("%d",&nums[i]);
        }
        for(int i=2;i<=k;i++){
            int maxx = nums[i-1];
            int minn = nums[i-1];
            for(int j=i-2;j>=0;j--){
                if((nums[j]>minn&&nums[i]>minn)||(nums[j]<maxx&&nums[i]<maxx)){
                    if(f[j]+1>f[i])
                        f[i] = f[j] + 1;
                }
                maxx = max(nums[j],maxx);
                minn = min(nums[j],minn);
            }
        }
        printf("Case #%d: %d\n",tt,f[k]-1);
    }
    return 0;
}
