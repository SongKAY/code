class Solution {
public:
    int result = 0;
    int dfs(int x,int y,vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x>=n||y>=m||x<0||y<0||grid[x][y]==0)
            return 0;
        grid[x][y] = 0;
        int sum = dfs(x+1,y,grid) + dfs(x-1,y,grid) + dfs(x,y+1,grid) + dfs(x,y-1,grid) + 1;
        result = max(result,sum);
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                }
            }
        }
        return result;
    }
};
