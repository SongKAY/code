#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main(){
    
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    while(n&&m){
        long long cnt = 1;
        for(int i=1;i<n;i++){
            cnt *= n + m - i;
            cnt /= i;
            if(cnt>k)
                break;
        }
        if(k<=cnt){
            s += 'a';
            n -= 1;
        }
        else{
            s +='z';
            m -= 1;
            k -= cnt;
        }
    }
    if(k!=1)
        cout<<"-1"<<endl;
    else{
        while(n--)
            s += 'a';
        while(m--)
            s += 'z';
        cout<<s<<endl;
    }
    return 0;
}
