class Solution {
public:
    bool dfs(int t,vector<vector<int>> graph,vector<int> &color,int flag){
        if(color[t]==flag)
            return true;
        if(color[t]&&color[t]!=flag)
            return false;
        int m = graph[t].size();
        color[t] = flag;
        for(int i=0;i<m;i++){
            int temp = graph[t][i];
            if(!dfs(temp,graph,color,-1*flag))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty())
            return false;
        int n = graph.size();
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(i,graph,color,1))
                    return false;
            }
        }
        return true;
    }
};
