class Solution {
public:
    void dfs(int x,int y,int n,int m,vector<vector<int>>& A){
        int dir[4][2] = {1,0,0,1,-1,0,0,-1};
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||!A[dx][dy])
                continue;
            A[dx][dy] = 0;
            dfs(dx,dy,n,m,A);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for(int i=0;i<n;i++){
            if(A[i][0]==1){
                A[i][0] = 0;
                dfs(i,0,n,m,A);
            }
            if(A[i][m-1]==1){
                A[i][m-1] = 0;
                dfs(i,m-1,n,m,A);
            }
        }
        for(int j=0;j<m;j++){
            if(A[0][j]==1){
                A[0][j] = 0;
                dfs(0,j,n,m,A);
            }
            if(A[n-1][j]==1){
                A[n-1][j] = 0;
                dfs(n-1,j,n,m,A);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==1)
                    cnt ++;
            }
        }
        return cnt;
    }
};
