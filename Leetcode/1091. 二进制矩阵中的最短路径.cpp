class Solution {
public:
    int bfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& flag){
        queue<pair<vector<int>,int>> q;
        int n = grid.size();
        q.push(make_pair(vector<int>{x,y},1));
        int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
        while(!q.empty()){
            int tx = q.front().first[0];
            int ty = q.front().first[1];
            int step = q.front().second;
            q.pop();
            if(tx==n-1&&ty==n-1)
                return step;
            for(int i=0;i<8;i++){
                int dx = tx + dir[i][0];
                int dy = ty + dir[i][1];
                if(dx<0||dx>=n||dy<0||dy>=n||flag[dx][dy]||grid[dx][dy])
                    continue;
                flag[dx][dy] = 1;
                q.push(make_pair(vector<int>{dx,dy},step+1));
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> flag(n,vector<int>(n,0));
        if(grid[0][0]!=0||grid[n-1][n-1]!=0)
            return -1;
        flag[0][0] = 1;
        return bfs(0,0,grid,flag);
        
    }
};
