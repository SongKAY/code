class Solution {
public:
    struct node{
        int x;
        int y;
        int step=0;
        node(int dx,int dy,int s){
            x = dx;
            y = dy;
            step = s;
        }
    };
    int bfs(vector<vector<int>> grid,vector<vector<int>> visit){
        int n = grid.size();
        if(grid[0][0])
            return -1;
        queue<node> q;
        node a(0,0,1);
        q.push(a);
        visit[0][0] = 1;
        int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
        while(!q.empty()){
            node t = q.front();
            q.pop();
            if(t.x==n-1&&t.y==n-1)
                return t.step;
            for(int i=0;i<8;i++){
                int dx = t.x + dir[i][0];
                int dy = t.y + dir[i][1];
                if(dx<0||dy<0||dx>=n||dy>=n)
                    continue;
                if(grid[dx][dy]||visit[dx][dy])
                    continue;
                visit[dx][dy] = 1;
                node s(dx,dy,t.step+1);
                q.push(s);
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> visit(n,vector<int>(n,0));
        return bfs(grid,visit);
    }
};
