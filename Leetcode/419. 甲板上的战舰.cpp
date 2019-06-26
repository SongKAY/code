class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty())
            return 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> flag(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='X'||flag[i][j])
                    continue;
                int x = i+1;
                int y = j+1;
                flag[i][j] = 1;
                cnt += 1;
                while(x<n&&board[x][j]=='X'){
                    flag[x][j] = 1;
                    x++;
                }
                if(x==i+1){
                    while(y<m&&board[i][y]=='X'){
                        flag[i][y] = 1;
                        y++;
                    }
                }
            }
        }
        return cnt;
    }
};
