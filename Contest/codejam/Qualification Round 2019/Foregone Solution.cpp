#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int t){
    while(t!=0){
        int n = t%10;
        if(n==4)
            return false;
        t = t/10;
    }
    return true;
}
int main(){
    
    int n ;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        int result1 = 0;
        int result2 = 0;
        vector<int> v;
        while(m!=0){
           v.push_back(m%10);
           m = m/10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]==4){
                result1 = result1*10 + 1;
                result2 = result2 * 10 + 3;
            }
            else{
                result1 = result1 * 10 + v[i];
                result2 = result2 * 10;
            }
        }
        printf("Case #%d: %d %d\n",i,result1,result2);
    }
    return 0;
}
