#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int main(){
    
    string s;
    while(cin>>s){
        string s1,s2;
        int pos = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==';'){
                pos = 1;
                continue;
            }
            if(!pos)
                s1 += s[i];
            else
                s2 += s[i];
        }
        if(s1.length()!=s2.length())
            cout<<"false"<<endl;
        else{
            int flag = 0;
            for(int i=0;i<s1.length();i++){
                if(s1[i]!=s2[0])
                    continue;
                string temp = s1.substr(i) + s1.substr(0,i);
                if(temp!=s2)
                    continue;
                else{
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }
    }
    return 0;
}
