class Solution {
public:
    struct node{
        int num;
    }m[10001];
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> result;
        if(barcodes.empty())
            return result;
        int n = barcodes.size();
        set<int> s;
        vector<pair<int,int>>v;
        map<int,int> m;
        for(int i=0;i<n;i++){
            s.insert(barcodes[i]);
            m[barcodes[i]]++;
        }
        set<int>::iterator it = s.begin();
        for(it;it!=s.end();it++)
            v.push_back(pair<int,int>(*it,m[*it]));
        sort(v.begin(),v.end(),cmp);
        result = vector<int>(n,0);
        int k = 0;
        for(int i=0;i<2;i++){
            for(int j=i;j<n;j+=2){
                if(v[k].second){
                    result[j] = v[k].first;
                    v[k].second -= 1;
                }
                else{
                    k++;
                    result[j] = v[k].first;
                    v[k].second -= 1;
                }
            }
        }
        return result;
    }
};
