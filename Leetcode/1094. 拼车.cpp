class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.empty())
            return true;
        set<int> day;
        vector<int> start(2001,0);
        vector<int> end(2001,0);
        for(int i=0;i<trips.size();i++){
            day.insert(trips[i][1]);
            day.insert(trips[i][2]);
            start[trips[i][1]] += trips[i][0];
            end[trips[i][2]] += trips[i][0];
        }
        set<int>::iterator it = day.begin();
        int cur = 0;
        for(;it!=day.end();it++){
            cur -= end[*it];
            cur += start[*it];
            if(cur>capacity)
                return false;
        }
        return true;
    }
};
