class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> path(N+1,vector<int>(N+1,INT_MAX));
        vector<int> dis(N+1,INT_MAX);
        int m = times.size();
        for(int i=0;i<m;i++){
            int a = times[i][0];
            int b = times[i][1];
            int w = times[i][2];
            path[a][b] = w;
        }
        for(int i=1;i<=N;i++){
            dis[i] = path[K][i];
        }
        dis[K] = 0;
        int result = 0;
        vector<int> flag(N+1,0);
        flag[K] = 1;
        for(int i=1;i<N;i++){
            int minx = INT_MAX;
            int u = -1;
            for(int j=1;j<=N;j++){
                if(flag[j])
                    continue;
                if(dis[j]<minx){
                    minx = dis[j];
                    u = j;
                }
            }
            if(u==-1){
                return -1;
            }
            flag[u] = 1;
            result = max(result,minx);
            for(int j=1;j<=N;j++){
                if(flag[j]||path[u][j]==INT_MAX)
                    continue;
                if(dis[j]>dis[u]+path[u][j])
                    dis[j] = dis[u]+path[u][j];
            }
        }
        return result;
    }
};
