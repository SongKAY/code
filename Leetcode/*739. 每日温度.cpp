class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n,0);
        stack<int> s;
        T.push_back(0);
        for(int i=0;i<=n;i++){
            while(!s.empty()&&T[i]>T[s.top()]){
                result[s.top()] = (i-s.top());
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};
