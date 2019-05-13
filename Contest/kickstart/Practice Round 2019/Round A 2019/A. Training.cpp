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
        int n,p;
        scanf("%d %d",&n,&p);
        int maxnum = 0;
        int maxx = 0;
        map<int,int> m;
        vector<int> nums;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            nums.push_back(a);
            m[a] ++;
            if(m[a]>maxnum)
                maxx = a;
            maxnum = max(m[a],maxnum);
        }
        int result = 0;
        if(maxnum>=p)
            result = 0;
        else{
            sort(nums.begin(),nums.end());
            result = nums[p-1] * p;
            int sum = 0;
            for(int i=0;i<p;i++){
                sum += nums[i];
            }
            result = min(result,nums[p-1]*p-sum);
            for(int i=p;i<n;i++){
                sum -= nums[i-p];
                sum += nums[i];
                result = min(result,nums[i]*p-sum);
            }
           
        }
        printf("Case #%d: %d\n",tt,result);
    }
    return 0;
}
