class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int result = 0;
        for(auto a:A){
            sum = (sum+a)%K;
            if(sum<0)
                sum += K;
            result += m[sum];
            m[sum] ++;
        }
        return result;
    }
};
