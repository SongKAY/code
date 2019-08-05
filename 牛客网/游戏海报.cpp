#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        int cnt = 0;
        int len = s.length();
        for(char a='a';a<='z';a++){
            int temp = 0;
            for(int i=0;i<len;i++){
                if(s[i]==a)
                    temp ++;
            }
            cnt += len + 1 - temp;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
