class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int result = 0;
        for(auto i:nums){
            sum += i;
            if(m[sum-k]!=0)
                result += m[sum-k];
            m[sum] += 1;
        }
        return result;
    }
};
