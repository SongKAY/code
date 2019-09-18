class Solution {
public:
    vector<vector<string>> result;
    bool valid(int row,int col,vector<string>temp,int n){
        for(int i=0;i<n;i++){
            if(temp[i][col]=='Q')
                return false;
            if(temp[row][i]=='Q')
                return false;
        }
        for(int i=0;i<n;i++){
            if(row+i<n&&col+i<n&&temp[row+i][col+i]=='Q')
                return false;
            if(row-i>=0&&col-i>=0&&temp[row-i][col-i]=='Q')
                return false;
            if(row-i>=0&&col+i<n&&temp[row-i][col+i]=='Q')
                return false;
            if(col-i>=0&&row+i<n&&temp[row+i][col-i]=='Q')
                return false;
        }
        return true;
    }
    void dfs(int row,vector<string> temp,int n){
        if(row==n){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(valid(row,i,temp,n)){
                temp[row][i] = 'Q';
                dfs(row+1,temp,n);
                temp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        dfs(0,temp,n);
        return result;
    }
};
