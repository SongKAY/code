class Solution {
public:
    int book[1001][1001];
    void dfs(int x,int y,vector<vector<char>>& board){
        int dir[4][2] = {1,0,0,1,-1,0,0,-1};
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx>=0&&dx<m&&dy>=0&&dy<n&&!book[dx][dy]&&board[dx][dy]=='O'){
                book[dx][dy]=1;
                dfs(dx,dy,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        memset(book,0,sizeof(book));
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                book[0][i] = 1;
                dfs(0,i,board);
            }
            if(board[m-1][i]=='O'){
                book[m-1][i] = 1;
                dfs(m-1,i,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                book[i][0] = 1;
                dfs(i,0,board);
            }
            if(board[i][n-1]=='O'){
                book[i][n-1] = 1;
                dfs(i,n-1,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(book[i][j])
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
