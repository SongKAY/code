#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        for(int i=0;i<s.length();i++){
            if(s[i]<='z'&&s[i]>='a')
                cout<<s[i];
        }
        for(int i=0;i<s.length();i++){
            if(s[i]<='Z'&&s[i]>='A')
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
