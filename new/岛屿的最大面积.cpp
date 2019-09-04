class Solution {
public:
    int dfs(int x,int y,vector<vector<int>> &grid){
        grid[x][y] = -1;
        int result = 1;
        int n = grid.size();
        int m = grid[0].size();
        if(x+1<n&&grid[x+1][y]==1)
            result += dfs(x+1,y,grid);
        if(x-1>=0&&grid[x-1][y]==1)
            result += dfs(x-1,y,grid);
        if(y+1<m&&grid[x][y+1]==1)
            result += dfs(x,y+1,grid);
        if(y-1>=0&&grid[x][y-1]==1)
            result += dfs(x,y-1,grid);
        return result; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        if(grid.empty())
            return result;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j] = -1;
                    result = max(result,dfs(i,j,grid));
                }
            }
        }
        return result;
    }
};
