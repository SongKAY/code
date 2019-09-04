class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int minvalue = nums[0];
        int maxvalue = nums[0];
        for(auto i:nums){
            maxvalue = max(maxvalue,i);
            minvalue = min(minvalue,i);
        }
        if(maxvalue<=0)
            return maxvalue;
        int result = 0;
        int temp = 0;
        for(auto i:nums){
            if(result+i<0)
                result = 0;
            else{
                result += i;
                temp = max(result,temp);
            }
        }
        return temp;
    }
};
