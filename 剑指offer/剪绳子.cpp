class Solution {
public:
    int result = 0;
    void dfs(int number,int k,int temp){
        if(number==0){
            if(k==1)
                return;
            result = max(result,temp);
            return;
        }
        for(int i=1;i<=number;i++){
            dfs(number-i,k+1,temp*i);
        }
    }
    int cutRope(int number) {
        int temp = 1;
        dfs(number,0,temp);
        return result;
    }
};
