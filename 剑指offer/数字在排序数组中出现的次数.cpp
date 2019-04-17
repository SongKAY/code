class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        map<int,int> m;
        for(int i=0;i<data.size();i++){
            m[data[i]] ++;
        }
        return m[k];
    }
};
