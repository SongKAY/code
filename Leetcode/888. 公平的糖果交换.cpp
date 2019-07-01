class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        long long sum1 = 0;
        long long sum2 = 0;
        vector<int> result;
        for(auto a:A)
            sum1 += a;
        for(auto b:B)
            sum2 += b;
        long long diff = (sum1-sum2)/2;
        map<int,int> m;
        for(auto a:A){
            m[a] = 1;
        }
        map<int,int> n;
        for(auto b:B)
            n[b] = 1;
        for(auto a:A){
            if(a-diff<0)
                continue;
            if(n[a-diff]){
                result.push_back(a);
                result.push_back(a-diff);
                break;
            }
        }
        return result;
    }
};
