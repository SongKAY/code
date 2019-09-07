class Solution {
public:
    bool check(int x,int y,int k){
        int sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
            if(sum>k)
                return false;
        }
        while(y){
            sum += y % 10;
            y /= 10;
            if(sum>k)
                return false;
        }
        return true;
    }
    int dfs(int x,int y,int n,int m,int k,vector<vector<int>> &flag){
        int result = 0;
        if(!check(x,y,k)||flag[x][y])
            return result;
        result += 1;
        flag[x][y] = 1;
        if(x+1<n)
            result += dfs(x+1,y,n,m,k,flag);
        if(y+1<m)
            result += dfs(x,y+1,n,m,k,flag);
        if(y-1>=0)
            result += dfs(x,y-1,n,m,k,flag);
        if(x-1>=0)
            result += dfs(x-1,y,n,m,k,flag);
        return result;
    }
    int movingCount(int threshold, int rows, int cols)
    {   
        vector<vector<int>> flag(rows,vector<int>(cols,0));
        if(threshold<0)
            return 0;
        return dfs(0,0,rows,cols,threshold,flag);
    }
};
