#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
    
    int n,k;
    while(cin>>n>>k){
        vector<int> temp(n,0);
        for(int i=0;i<n;i++)
            cin>>temp[i];
        int left = 0;
        int nx = 0;
        int m = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            nx += temp[i];
            m += (1-temp[i]);
            if(m<=k)
                ans = max(ans,nx+m);
            else{
                while(left<i&&m>k){
                    m -= (1-temp[left]);
                    nx -= temp[left];
                    left ++;
                }
                ans = max(ans,nx+m);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
