#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int> temp(n,0);
    for(int i=0;i<n;i++)
        cin>>temp[i];
    int sum = 0;
    for(auto c:temp)
        sum += c;
    if(sum%n)
        cout<<-1<<endl;
    else{
        int result = 0;
        int flag = 0;
        int k = sum / n;
        for(int i=0;i<n;i++){
            if(temp[i]==k)
                continue;
            int diff = abs(temp[i]-k);
            if(diff%2){
                flag = 1;
                break;
            }
            result += diff;
        }
        if(flag)
            cout<<-1<<endl;
        else
            if(result%4)
                cout<<-1<<endl;
            else
                cout<<result/4<<endl;
    }
    return 0;
}
