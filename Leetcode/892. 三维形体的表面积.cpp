class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0;
        if(grid.empty())
            return result;
        int n =grid.size();
        int m =grid[0].size();
        int left = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j])
                    left ++;
            }
        }
        result += 2*(n*m - left);
        for(int i=0;i<n;i++){
            result += grid[i][0];
            for(int j=1;j<m;j++){
                if(grid[i][j]>grid[i][j-1])
                    result += (grid[i][j]-grid[i][j-1]);
            }
            result += grid[i][m-1];
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]>grid[i][j+1])
                    result += (grid[i][j]-grid[i][j+1]);
            }
        }
        for(int i=0;i<m;i++){
            result += grid[0][i];
            for(int j=1;j<n;j++){
                if(grid[j][i]>grid[j-1][i])
                    result += grid[j][i] - grid[j-1][i];
            }
            result += grid[n-1][i];
            for(int j=n-2;j>=0;j--){
                if(grid[j][i]>grid[j+1][i])
                    result += grid[j][i] - grid[j+1][i];
            }
        }
        return result;
    }
};
