#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;


int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        vector<char> temp(m,' ');
        vector<vector<char>> grid(n,temp);
        int left = n*m - k; //被困住
        string str = "POSSIBLE";
        if(left==1){
            str="IMPOSSIBLE";
        }
        printf("Case #%d: ",tt);
        cout<<str<<endl;
        if(str=="POSSIBLE"){
            if(m!=1){
                for(int i=0;i<n;i++){
                    if(left!=0){
                        if(i==0)
                            grid[i][0] = 'E';
                        else
                            grid[i][0] = 'N';
                        left -= 1;
                    }
                    else{
                        grid[i][0] = 'W';
                    }
                    for(int j=1;j<m;j++){
                        if(left==0){
                            grid[i][j]='S';
                        }
                        else{
                            if(i==0)
                                grid[i][j] = 'W';
                            else
                                grid[i][j]='N';
                            left-=1;
                        }
                    }
                }
            }
            else{
                int start = 0;
                while(left!=0){
                    if(!start)
                        grid[start][0] = 'S';
                    else
                        grid[start][0] = 'N';
                    left -= 1;
                    start += 1;
                }
                while(start<n){
                    grid[start][0] = 'S';
                    start += 1;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
