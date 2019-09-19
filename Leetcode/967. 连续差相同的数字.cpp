class Solution {
public:
    vector<int> result;
    void dfs(int t,int pre,int N,int K,int num){
        if(t==N){
            result.push_back(num);
            return;
        }
        if(t==0){
            for(int i=0;i<=9;i++){
                if(i==0&&N!=1)
                    continue;
                dfs(t+1,i,N,K,num*10+i);
            }
        }
        else{
            int a = pre - K;
            if(a>=0)
                dfs(t+1,a,N,K,num*10+a);
            if(K!=0){
                a = pre + K;
                if(a<=9)
                    dfs(t+1,a,N,K,num*10+a);
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        dfs(0,0,N,K,0);
        return result;
    }
};
