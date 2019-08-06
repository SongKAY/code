#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isok(int mid,vector<int> temp,int m){
    int cnt = 0;
    int k = 0;
    int n = temp.size();
    for(int i=0;i<n;i++){
        if(mid<temp[i])
            return false;
    }
    for(int i=0;i<n;i++){
        if(cnt+temp[i]>mid){
            cnt = temp[i];
            k += 1;
        }
        else
            cnt += temp[i];
    }
    if(cnt!=0)
        k += 1;
    if(k>m)
        return false;
    return true;
}

int main(){
    
    int n,m;
    while(cin>>n>>m){
        vector<int> temp(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>temp[i];
            sum += temp[i];
        }
        int l = 0;
        int r = sum;
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(isok(mid,temp,m))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout<<l<<endl;
    }
    return 0;
}
