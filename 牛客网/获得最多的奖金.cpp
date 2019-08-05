#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++)
        cin>>prices[i];
    long long result = 0;
    int l = 0;
    int r = n-1;
    long long left = 0;
    long long right = 0;
    while(l<=r){
        if(left==right&&l!=r){
            left += prices[l];
            right += prices[r];
            l ++;
            r --;
        }
        if(left<right){
            left += prices[l];
            l ++;
        }
        else if(right<left){
            right += prices[r];
            r --;
       }
        if(left==right){
            result = max(result,left);
        }
    }
    cout<<result<<endl;
    return 0;
}
