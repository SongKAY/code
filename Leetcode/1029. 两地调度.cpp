class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]-a[0] < b[1]-b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(),costs.end(),cmp);
        int sum=0;
        for(int i=0;i<n/2;i++)
            sum+=costs[i][1];
        for(int i=n/2;i<n;i++)
            sum+=costs[i][0];
        return sum;
    }
};
