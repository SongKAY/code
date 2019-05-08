#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
vector<char> temp{'A','B','C'};

bool cmp(string a, string b){
    map<char,int> m;
    for(int i=0;i<temp.size();i++)
        m[temp[i]] = i;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i])
            continue;
        return m[a[i]]<m[b[i]];
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int l;
        scanf("%d",&l);
        string str;
        vector<string> s;
        for(int i=0;i<3;i++){
            cin>>str;
            s.push_back(str);
        }
        vector<string> fix(s);
        map<string,int> flag;
        sort(temp.begin(),temp.end());
        do{
            sort(s.begin(),s.end(),cmp);
            flag[s[1]] = 1;
        }while(next_permutation(temp.begin(),temp.end()));
        printf("Case #%d: ",tt);
        for(int i=0;i<3;i++){
            if(flag[fix[i]])
                cout<<"YES";
            else
                cout<<"NO";
            if(i!=2)
                cout<<' ';
            else
                cout<<endl;
        }
    }
    return 0; 
}
