#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    if(a[0]==b[0])
        return a[1]<b[1];
    else
        return a[0]<b[0];
}
int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n,m;
        scanf("%d %d",&n,&m);
        map<int,int> row;
        vector<vector<int>> temp;
        for(int i=1;i<=m;i++)
            row[i] = 0;
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            vector<int> c{a,b};
            temp.push_back(c);
        }
        sort(temp.begin(),temp.end(),cmp);
        int a = temp[0][0];
        int b = temp[0][1];
        row[a] += 1;
        if(a!=b)
            row[b] += 1;
        for(int i=1;i<temp.size();i++){
            if(temp[i][0]==temp[i-1][0]&&temp[i][1]==temp[i-1][1])
                continue;
            a = temp[i][0];
            b = temp[i][1];
            row[a]++;
            if(a!=b)
                row[b]++;
        }
        int result =0;
        for(int i=1;i<=m;i++){
            result = max(result,row[i]);
        }
        printf("Case #%d: %d\n",tt,result);
    }
    return 0;
}
