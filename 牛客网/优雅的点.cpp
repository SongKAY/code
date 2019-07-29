/*考虑三种情况 相同 1个为0 不同*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        int cnt = 0;
        for(int i=1;i*i<n;i++){
            for(int j=i;j*j<n;j++){
                if(i*i+j*j==n){
                    if(i!=j)
                        cnt += 8;
                    else
                        cnt += 4;
                }
            }
        }
        for(int i=1;i*i<=n;i++){
            if(i*i==n){
                cnt += 4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
