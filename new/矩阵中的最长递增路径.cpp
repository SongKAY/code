class Solution {
public:
    int dp(int x,int y,vector<vector<int>> &f,vector<vector<int>>& matrix){
        if(f[x][y])
            return f[x][y];
        f[x][y] = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        int dir[4][2] = {1,0,0,1,-1,0,0,-1};
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0||dy<0||dx>=n||dy>=m||matrix[dx][dy]>=matrix[x][y])
                continue;
            f[x][y] = max(f[x][y],dp(dx,dy,f,matrix)+1);
        }
        return f[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int result  = 0;
        vector<vector<int>> f(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result,dp(i,j,f,matrix));
            }
        }
        return result;
    }
};
