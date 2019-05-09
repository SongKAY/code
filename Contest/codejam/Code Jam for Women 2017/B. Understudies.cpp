#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        int N;
        scanf("%d",&N);
        vector<double> num(2*N,0);
        for(int i=0;i<2*N;i++){
            cin>>num[i];
        }
        sort(num.begin(),num.end());
        double result = 1;
        for(int i=0;i<N;i++){
            result *= (1.0 - num[i]*num[2*N-1-i]);
        }
        printf("Case #%d: %.6f\n",tt,result);
    }
    return 0;
}
