class Solution {
public:
    int getf(int x,vector<int> &f){
        if(f[x]==x)
            return x;
        else{
            f[x] = getf(f[x],f);
            return f[x];
        }
    }
    void merge(int x,int y,vector<int> &f){
        int t1 = getf(x,f);
        int t2 = getf(y,f);
        if(t1!=t2){
            f[t2] = t1;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if(n<=1)
            return 0;
        vector<int> f(n,0);
        for(int i=0;i<n;i++)
            f[i] = i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = stones[i][0];
                int y1 = stones[i][1];
                int x2 = stones[j][0];
                int y2 = stones[j][1];
                if(x1==x2||y1==y2){
                    merge(i,j,f);
                }
            }
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if(f[i]==i)
                result ++;
        }
        return n - result;
    }
};
