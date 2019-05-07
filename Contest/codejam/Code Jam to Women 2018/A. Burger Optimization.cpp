#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n;
        scanf("%d",&n);
        int result = 0;
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        sort(nums.begin(),nums.end());
        vector<int> temp;
        for(int i=0;i<n/2;i++){
            temp.push_back(i);
            temp.push_back(i);
        }
        if(n%2)  
            temp.push_back(n/2);
        else{
            temp.push_back(n/2);
            temp.push_back(n/2);
        }
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<' '<<temp[i]<<endl;
            result += (nums[i]-temp[i]) * (nums[i]-temp[i]);
        }
        printf("Case #%d: %d\n",tt,result);
    }    
    return 0;
}
