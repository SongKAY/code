class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        else
            return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            result.insert(result.begin()+people[i][1],people[i]);
        }
        return result;
    }
};
