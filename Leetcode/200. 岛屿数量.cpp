class Solution {
public:
    int color = 0;
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    void dfs(int x,int y,vector<vector<char>> &grid,int color){
        grid[x][y] = color +'0';
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||grid[dx][dy]!='1')
                continue;
            dfs(dx,dy,grid,color);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        color = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    color += 1;
                    dfs(i,j,grid,color);
                }
            }
        }
        return (color - 1);
    }
};
