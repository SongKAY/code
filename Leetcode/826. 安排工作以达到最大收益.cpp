class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second!=b.second)
            return a.second>b.second;
        return a.first<b.first;
    }
    static bool cmp1(int a,int b){
        return a>b;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> work;
        int n = profit.size();
        int m = worker.size();
        for(int i=0;i<n;i++){
            work.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(work.begin(),work.end(),cmp);
        sort(worker.begin(),worker.end(),cmp1);
        int i=0;
        int j=0;
        int result = 0;
        while(i<m){
            while(j<n&&work[j].first>worker[i]){
                j++;
            }
            if(j>=n)
                break;
            result += work[j].second;
            i++;
        }
        return result;
    }
};
