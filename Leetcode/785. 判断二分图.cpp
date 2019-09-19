class Solution {
public:
    bool dfs(int t,vector<int>&color,vector<vector<int>>&graph,int flag){
        if(color[t]==flag)
            return true;
        if(color[t]==-flag)
            return false;
        color[t] = flag;
        for(int i=0;i<graph[t].size();i++){
            if(!dfs(graph[t][i],color,graph,-flag))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(!n)
            return true;
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(!color[i]){
                if(!dfs(i,color,graph,1))
                    return false;
            }
        }
        return true;
    }
};
