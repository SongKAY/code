class Solution {
public:
    bool check(int t,int color,vector<int> &edge,vector<int> &temp){
        if(edge.empty())
            return true;
        for(auto a:edge){
            if(temp[a]==color)
                return false;
        }
        return true;
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        map<int,vector<int>> m;
        for(auto i:paths){
            m[i[0]-1].push_back(i[1]-1);
            m[i[1]-1].push_back(i[0]-1);
        }
        vector<int> temp(N,0);
        for(int i=0;i<N;i++){
            for(int j=1;j<=4;j++){
                if(check(i,j,m[i],temp)){
                    temp[i] = j;
                    break;
                }
            }
        }
        return temp;
    }
};
