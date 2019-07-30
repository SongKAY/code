#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int> temp;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            temp.push_back(a);
        }
        int four = 0;
        int two = 0;
        for(auto a:temp){
            if(a%4==0)
                four ++;
            else if(a%2==0)
                two ++;
        }
        if(four*2+two-1>=n-1){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
