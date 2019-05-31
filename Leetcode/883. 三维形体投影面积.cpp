class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    cnt ++;
            }
        }
        for(int i=0;i<n;i++){
            int maxcnt = 0;
            for(int j=0;j<m;j++){
                maxcnt = max(maxcnt,grid[i][j]);
            }
            cnt += maxcnt;
        }
        
        for(int i=0;i<m;i++){
            int maxcnt = 0;
            for(int j=0;j<n;j++){
                maxcnt = max(maxcnt,grid[j][i]);
            }
            cnt += maxcnt;
        }
        return cnt;
    }
};
