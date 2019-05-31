#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        if(n==0)
            return 3;
        vector<int> m(n,0);
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
        }
        sort(m.begin(),m.end());
        int result = 0;
        int cnt = 1;
        int pre = m[0];
        for(int i=1;i<n;){
            if(cnt==3){
                cnt = 1;
                pre = m[i];
                i++;
            }
            else{
                if(m[i]-pre>10){
                    result += 1;
                    cnt += 1;
                    pre = pre+10>m[i]?m[i]:pre+10;
                }
                else{
                    cnt += 1;
                    pre = m[i];
                    i++;
                }
            }
        }
        if(cnt!=3){
            result += 3 - cnt;
        }
        cout<<result<<endl;
    }
    return 0;
}
