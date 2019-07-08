小易有n块砖块，每一块砖块有一个高度。小易希望利用这些砖块堆砌两座相同高度的塔。为了让问题简单，砖块堆砌就是简单的高度相加，某一块砖只能使用在一座塔中一次。小易现在让能够堆砌出来的两座塔的高度尽量高，小易能否完成呢。
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 500000
int height[52];
int sum[52];
int n;
int ans=0;
void dfs(int n,int sum1,int sum2){
    if(sum1==sum2)
        ans=max(ans,sum1);
    if(n==0)
        return;
    if(sum1>MAX)
        return;
    if(sum1+sum[n]<sum2)
        return;
    if((sum1+sum2+sum[n])<=ans*2)
        return;
    dfs(n-1,min(sum1+height[n],sum2),max(sum1+height[n],sum2));
    dfs(n-1,min(sum2+height[n],sum1),max(sum2+height[n],sum1));
    dfs(n-1,sum1,sum2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>height[i];
    sort(height+1,height+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+height[i];
    dfs(n,0,0);
    cout<<(ans?ans:-1)<<endl;
}
