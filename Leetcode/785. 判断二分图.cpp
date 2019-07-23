class Solution {
public:
    bool dfs(int t,vector<vector<int>> graph,vector<int>&color, int flag){
        if(color[t]==flag)
            return true;
        if(color[t]!=0&&color[t]!=flag)
            return false;
        color[t] = flag;
        int m = graph[t].size();
        for(int i=0;i<m;i++){
            int next = graph[t][i];
            if(!dfs(next,graph,color,-1*flag))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty())
            return true;
        int n = graph.size();
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(!color[i]){
                if(!dfs(i,graph,color,1))
                    return false;
            }
        }
        return true;
    }
};
