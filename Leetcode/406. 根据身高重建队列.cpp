class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> q;
        if(people.empty())
            return q;
        sort(people.begin(),people.end(),cmp);
        for(auto c:people){
            q.insert(q.begin()+c[1],c);
        }
        return q;
    }
};
