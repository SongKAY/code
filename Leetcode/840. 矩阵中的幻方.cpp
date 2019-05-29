class Solution {
public:
    bool check(int x,int y,vector<vector<int>> & grid){
        int n = grid.size();
        int m = grid[0].size();
        map<int,int> ma;
        if(x+2>=n||y+2>=m)
            return false;
        for(int i=x;i<=x+2;i++){
            for(int j=y;j<=y+2;j++){
                if(ma[grid[i][j]])
                    return false;
                ma[grid[i][j]] = 1;
            }
        }
        for(int i=1;i<=9;i++){
            if(ma[i]!=1)
                return false;
        }
        int temp = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        for(int i=0;i<3;i++){
            int cnt = grid[x+i][y]+grid[x+i][y+1]+grid[x+i][y+2];
            if(cnt!=temp)
                return false;
        }
        for(int i=0;i<3;i++){
            int cnt = grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i];
            if(cnt!=temp)
                return false;
        }
        if(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]!=temp)
            return false;
        if(grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y]!=temp)
            return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i,j,grid))
                    cnt++;
            }   
        }
        return cnt;
    }
};
