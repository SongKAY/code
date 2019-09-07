class Solution {
public:
    int flag = 0;
    void dfs(vector<vector<char>> board,int x,int y,int len,string word,vector<vector<int>> ma){
        if(len==word.length()-1){
            flag = 1;
            return ;
        }
        if(flag)
            return;
        int n = board.size();
        int m = board[0].size();
        int dir[4][2] = {1,0,0,1,-1,0,0,-1};
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||ma[dx][dy]||board[dx][dy]!=word[len+1])
                continue;
            ma[x][y] = 1;
            dfs(board,dx,dy,len+1,word,ma);
            ma[x][y] = 0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> ma(n,vector<int>(m,0));
                    ma[i][j]=1;
                    dfs(board,i,j,0,word,ma);
                    if(flag)
                        return true;
                }
            }
        }
        return false;
    }
};
