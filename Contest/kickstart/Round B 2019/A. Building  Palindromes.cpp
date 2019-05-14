#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n,m;
        scanf("%d %d",&n,&m);
        string str;
        cin>>str;
        map<char,int> v;
        vector<map<char,int>> dict;
        for(char a='A';a<='Z';a++){
            v[a] = 0;
        }
        dict.push_back(v);
        for(int i=0;i<str.length();i++){
            v[str[i]] ++;
            dict.push_back(v);
        }
        int result = 0;
        while(m--){
            int s,e;
            scanf("%d %d",&s,&e);
            int len = e - s + 1;
            int cnt = 0;
            for(char a='A';a<='Z';a++){
                int b = dict[e][a] - dict[s-1][a];
                if(b%2!=0)
                    cnt++;
            }
            if(len%2==1){
                if(cnt==0||cnt==1)
                    result += 1;
            }
            else{
                if(cnt==0)
                    result += 1;
            }
        }
        printf("Case #%d: %d\n",tt,result);
    }
    return 0;
}
