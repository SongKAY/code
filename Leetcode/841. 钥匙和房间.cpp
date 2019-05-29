class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> key;
        map<int,int> m;
        m[0] = 1;
        key.push(0);
        while(!key.empty()){
            int start = key.front();
            key.pop();
            int ma = rooms[start].size();
            for(int i=0;i<ma;i++){
                if(m[rooms[start][i]])
                    continue;
                else{
                    m[rooms[start][i]] = 1;
                    key.push(rooms[start][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
            if(!m[i])
                return false;
        return true;
    }
};
