###Test set 2 TLE###

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
int flag[10000][10000];
string s;
void dfs(int x,int y,int n,int m,vector<char> result,int t){
    if(n==0&&m==0){
        if(x==t-1&&y==t-1){
            s="";
            for(int i=0;i<result.size();i++){
                s += result[i];
            }
            return;
        }
    }
    if(s!="")
        return;
    if(n>=1){
        int dx = x;
        int dy = y+1;
        int index1 = x * 10 + y;
        int index2 = dx * 10 + dy;
        if(dx>=0&&dx<t&&dy>=0&&dy<t&&!flag[index1][index2]){
            result.push_back('S');
            dfs(dx,dy,n-1,m,result,t);
            result.pop_back();
        }
    }
    if(m>=1){
        int dx = x+1;
        int dy = y;
        int index1 = x * 10 + y;
        int index2 = dx * 10 + dy;
        if(dx>=0&&dx<t&&dy>=0&&dy<t&&!flag[index1][index2]){
            result.push_back('E');
            dfs(dx,dy,n,m-1,result,t);
            result.pop_back();
        }
    }
    return;
}

int main(){
    
    int n;
    cin>>n;
    for(int epoch=1;epoch<=n;epoch++){
        memset(flag,0,sizeof(flag));
        int m;
        cin>>m;
        string str;
        cin>>str;
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 0;
        for(int i=0;i<str.length();i++){
            int index1 = x * 10 + y;
            int index2 = 0;
            if(str[i]=='S'){
                dx = x;
                dy = y + 1;
                index2 = dx * 10 + dy;
            }
            else{
                dx = x + 1;
                dy = y ;
                index2 = dx * 10 + dy;
            }
            flag[index1][index2] = 1;
            x = dx;
            y = dy;
        }
        s = "";
        vector<char> result;
        dfs(0,0,m-1,m-1,result,m);
        printf("Case #%d: ",epoch);
        cout<<s<<endl;
    }
    return 0;
}

