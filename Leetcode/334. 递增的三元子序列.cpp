class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto i:nums){
            if(i<=a)
                a = i;
            else if(i<=b)
                b = i;
            else
                return true;
        }
        return false;
    }
};
