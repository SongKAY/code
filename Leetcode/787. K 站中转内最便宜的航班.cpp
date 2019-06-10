class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        map<int,vector<pair<int,int>>> m;
        for(int i=0;i<flights.size();i++)
            m[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        queue<pair<int,int>> q;
        q.push(make_pair(src,0));
        int result = INT_MAX;
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int t = q.front().first;
                int price = q.front().second;
                q.pop();
                if(t==dst)
                    result = min(result,price);
                for(int i=0;i<m[t].size();i++){
                    if(price+m[t][i].second>result)
                        continue;
                    q.push(make_pair(m[t][i].first,price+m[t][i].second));
                }
            }
            cnt ++;
            if(cnt>K+1)
                break;
        }
        if(result==INT_MAX)
            return -1;
        return result;
    }
};
