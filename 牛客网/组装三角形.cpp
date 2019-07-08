牛牛手里有N根木棒,分别编号为1~N,现在他从N根里想取出三根木棒，使得三根木棒构成一个三角形,你能计算出牛牛有多少种取法吗?(考虑两种取法中使用的木棒编号有一个不一样就认为是不同的取法)。


#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            temp.push_back(a);
        }
        sort(temp.begin(),temp.end());
        int cnt = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=n-1;k>j;k--){
                    if(temp[i]+temp[j]>temp[k]){
                        cnt += k-j;
                        break;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
