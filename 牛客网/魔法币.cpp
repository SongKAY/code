#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;
    while(cin>>n){
        string s;
        while(n){
            if(n%2==1){
                s += '1';
                n = (n-1) / 2;
            }
            else{
                s += '2';
                n = (n-2) / 2;
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}
