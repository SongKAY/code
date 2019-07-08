//用等差数列求和公式
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n,l;
    while(~scanf("%d %d",&n,&l)){
        int flag = -1;
        int minx = 0;
        for(int i=l;i<=100;i++){
            if((n*2)%i)
                continue;
            int start = n * 2 / i - i + 1;
            if(start<0||start%2)
                continue;
            else{
                flag = start / 2;
                minx = i;
                break;
            }
        }
        if(flag==-1)
            printf("No\n");
        else{
            printf("%d",flag);
            minx -= 1;
            while(minx--)
                printf(" %d",++flag);
            printf("\n");
        }
    }
    return 0;
}
