class Solution {
public:
    int getf(int a,vector<int>&f){
        if(a==f[a])
            return a;
        f[a] = getf(f[a],f);
        return f[a];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        if(edges.empty())
            return result;
        int n = edges.size();
        vector<int> f(n+1,0);
        for(int i=1;i<=n;i++)
            f[i] = i;
        for(int i=0;i<n;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int t1 = getf(a,f);
            int t2 = getf(b,f);
            if(t1!=t2)
                f[t2] = t1;
            else{
                return edges[i];
            }
        }
        return result;
    }
};
