#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int m[1005][1005];
int flag[1005];
int cir[1005];
int check;

void dfs(int start,int pre, int t, int n, int step, vector<int> &temp){
    if(check)
        return;
    for(int i=1;i<=n;i++){
        if(!m[pre][i]||i==t)
            continue;
        else{
            if(flag[i]){
                if(i==start&&step){
                    check = 1;
                    for(int i=1;i<=n;i++){
                        if(flag[i])
                            temp.push_back(i);
                    }
                    return;
                }
                else
                    continue;
            }
            else{
                flag[i] = 1;
                dfs(start,i,pre,n,step+1,temp);
                flag[i] = 0;
            }
        }
    }
    return;
}

int cal_dis(int t,int* cir,int n){
    queue<pair<int,int>> q;
    q.push(make_pair(t,0));
    while(!q.empty()){
        int temp = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(int i=1;i<=n;i++){
            if(m[temp][i]){
                if(*(cir+i)){
                    return dis+1;
                }
                else{
                    q.push(make_pair(temp,dis+1));
                }
            }
        }
    }
    return 0;
}

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n;
        scanf("%d",&n);
        memset(m,0,sizeof(m));
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            m[a][b] = 1;
            m[b][a] = 1;
        }
        //circle
        check = 0;
        vector<int> circle;
        for(int i=1;i<=n;i++){
            memset(flag,0,sizeof(flag));
            flag[i] = 1;
            dfs(i,i,n,i,0,circle);
            if(check){
                break;
            }
        }
        memset(cir,0,sizeof(cir));
        for(int i=0;i<circle.size();i++){
            cir[circle[i]] = 1;
        }
        int dis[n+1];
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n;i++){
            if(cir[i])
                dis[i] = 0;
            else{
                dis[i] = cal_dis(i,cir,n);
            }
        }
        printf("Case #%d: ",tt);
        for(int i=1;i<=n;i++){
            cout<<dis[i];
            if(i!=n)
                cout<<' ';
            else
                cout<<endl;
        }
    }
    return 0;
}
