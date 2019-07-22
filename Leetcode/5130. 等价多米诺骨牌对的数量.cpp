class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.empty())
            return 0;
        int n = dominoes.size();
        for(int i=0;i<n;i++){
            if(dominoes[i][0]>dominoes[i][1]){
                int temp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = temp;
            }
        }
        map<pair<int,int>,int> m;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            pair<int,int> temp = make_pair(dominoes[i][0],dominoes[i][1]);
            m[temp] ++;
            s.insert(temp);
        }
        set<pair<int,int>>::iterator it = s.begin();
        int result = 0;
        for(;it!=s.end();it++){
            result += (m[*it] * (m[*it]-1) )/ 2;
        }
        return result;
    }
};
