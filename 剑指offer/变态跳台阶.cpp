/*每个台阶都可以选择跳或不跳,但最后一个台阶必须要跳,因此有2的(n-1)次方情况*/
/*或者从跳台阶中寻找灵感,可以跳1个或2个时f(n)=f(n-1)+f(n-2),则可以跳n个时f(n)=f(n-1)+f(n-2)+...+f(1)*/
class Solution {
public:
    int jumpFloorII(int number) {
        int dp[number+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        if(number>=3){
            for(int i=3;i<=number;i++)
                dp[i] = dp[i-1] *2 ;
        }
        return dp[number];
    } 
};
