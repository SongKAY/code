class Solution {
public:
    int result = 0;
    void dfs(int pos,int N,vector<int> flag){
        if(pos==N+1){
            result += 1;
            return;
        }
        for(int i=1;i<=N;i++){
            if(flag[i])
                continue;
            if(i%pos==0||pos%i==0){
                flag[i] = 1;
                dfs(pos+1,N,flag);
                flag[i] = 0;
            }
        }
        return;
    }
    int countArrangement(int N) {
        vector<int> flag(N+1,0);
        dfs(1,N,flag);
        return result;
    }
};
