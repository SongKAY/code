class Solution {
public:
    bool valid(int row,int col,int n,vector<string>vs){
        for(int i=0;i<n;i++){
            if(vs[row][i]=='Q'){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(vs[i][col]=='Q'){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(row-i>=0&&col-i>=0){
                if(vs[row-i][col-i]=='Q')
                    return false;
            }
            if(row+i<n&&col+i<n){
                if(vs[row+i][col+i]=='Q')
                    return false;
            }
        }
        for(int i=0;i<n;i++){
            if(row-i>=0&&col+i<n){
                if(vs[row-i][col+i]=='Q')
                    return false;
            }
            if(row+i<n&&col-i>=0){
                if(vs[row+i][col-i]=='Q')
                    return false;
            }
        }
        return true;
    }
    void dfs(int row,int n,vector<vector<string>>&v,vector<string>vs){
        if(row==n){
            v.push_back(vs);
            return;
        }
        for(int i=0;i<n;i++){
            if(valid(row,i,n,vs)){
                vs[row][i] = 'Q';
                dfs(row+1,n,v,vs);
                vs[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vs(n,string(n,'.'));
        vector<vector<string>> v;
        dfs(0,n,v,vs);
        return v;
    }
};
