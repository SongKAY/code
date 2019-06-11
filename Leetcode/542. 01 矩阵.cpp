class Solution {
public:
    void bfs(int x,int y,int n,int m, vector<vector<int>>& matrix, vector<vector<int>>& result){
        queue<pair<int,int>>q;
        q.push(make_pair(x,y));
        int dir[4][2] = {1,0,0,1,-1,0,0,-1};
        int cnt = 0;
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(matrix[i][j]==0){
                    result[x][y] = cnt;
                    flag = 1;
                    break;
                }
                for(int k=0;k<4;k++){
                    int dx = i+dir[k][0];
                    int dy = j+dir[k][1];
                    if(dx<0||dx>=n||dy<0||dy>=m)
                        continue;
                    q.push(make_pair(dx,dy));
                }
            }
            if(flag)
                break;
            cnt ++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> result = matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                    continue;
                bfs(i,j,n,m,matrix,result);
            }
        }
        return result;
    }
};
