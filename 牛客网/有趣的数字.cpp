/*注意考虑多种情况*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        vector<int> a;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            a.push_back(temp);
        }
        sort(a.begin(),a.end());
        int minx = a[0];
        int maxx = a[n-1];
        int mincnt = 0;
        int maxcnt = 0;
        for(int i=0;i<n;i++)
            if(a[i]==minx)
                mincnt ++;
        for(int i=0;i<n;i++)
            if(a[i]==maxx)
                maxcnt ++;
        int maxresult = 0;
        int minresult = 0;
        if(minx==maxx){
            maxresult = maxcnt * (maxcnt-1) / 2;
        }
        else
            maxresult = mincnt * maxcnt;
        int mintemp = a[n-1]-a[0];
        for(int i=1;i<n;i++){
            mintemp = min(mintemp,a[i]-a[i-1]);
        }
        if(mintemp == 0){
            int r = 1;
            int t = 1;
            while(r<n){
                while(r<n&&a[r]==a[r-1]){
                    r ++;
                    t ++;
                }
                if(t>1){
                    minresult += t * (t-1) / 2;
                    t = 1;
                }
                r ++;
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(a[i]-a[i-1]==mintemp)
                    minresult ++;
            }
        }
        cout<<minresult<<' '<<maxresult<<endl;
    }
    return 0;
}
