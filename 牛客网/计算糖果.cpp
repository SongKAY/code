#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int main(){
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        int ans1 = a + c;
        int flag = 0;
        if(ans1%2)
            flag = 1;
        else
            ans1 /= 2;
        int ans2 = c - ans1;
        int ans3 = d - ans2;
        if(ans2-ans3!=b)
            flag = 1;
        if(flag)
            cout<<"No"<<endl;
        else
            cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    }
    return 0;
}
