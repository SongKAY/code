class Solution {
public:
    int getf(int x,vector<int>&f){
        if(f[x]==x)
            return x;
        else{
            f[x] = getf(f[x],f);
            return f[x];
        }
    }
    
    void merge(int x,int y,vector<int>&f){
        int t1 = getf(x,f);
        int t2 = getf(y,f);
        if(t1!=t2)
            f[t2] = t1;
    }
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())
            return 0;
        int n = M.size();
        int m = M[0].size();
        vector<int> f(n,0);
        for(int i=0;i<n;i++)
            f[i] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j])
                    merge(i,j,f);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(f[i]==i)
                cnt ++;
        }
        return cnt;
    }
};
