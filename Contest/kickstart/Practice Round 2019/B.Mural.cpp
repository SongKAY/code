#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n;
        scanf("%d",&n);
        vector<int> nums;
        string str;
        cin>>str;
        for(int i=0;i<n;i++){
            int a = str[i] - '0';
            nums.push_back(a);
        }
        int k = n/2;
        int left = n-k;
        int maxnum = 0;
        int sum = 0;
        for(int i=0;i<left;i++){
            sum += nums[i];
        }
        maxnum = max(sum,maxnum);
        for(int i=left;i<n;i++){
            sum += nums[i];
            sum -= nums[i-left];
            maxnum = max(sum,maxnum);
        }
        printf("Case #%d: %d\n",tt,maxnum);
    }
    return 0;
}
