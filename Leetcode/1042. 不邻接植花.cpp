class Solution {
public:
    bool check(int t,int N,int temp,vector<int> &color,vector<int> m[10001]){
        vector<int> node = m[t];
        if(node.empty()){
            return true;
        }
        for(int i=0;i<node.size();i++){
            if(color[node[i]-1]==temp)
                return false;
        }
        return true;
    }

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> color(N,0);
        if(N==0)
            return color;
        vector<int> m[10001];
        for(int i=0;i<paths.size();i++){
            int x = paths[i][0];
            int y = paths[i][1];
            m[x].push_back(y);
            m[y].push_back(x);
        }
        color[0] = 1;
        for(int i=2;i<=N;i++){
            for(int j=1;j<=4;j++){
                if(check(i,N,j,color,m)){
                    color[i-1] = j;
                    break;
                }
            }
        }
        return color;
    }
};
