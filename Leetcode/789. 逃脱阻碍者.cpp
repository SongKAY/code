class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]);
        for(auto a:ghosts){
            int temp = abs(a[0]-target[0]) + abs(a[1]-target[1]);
            if(temp<dis)
                return false;
        }
        return true;
    }
};
