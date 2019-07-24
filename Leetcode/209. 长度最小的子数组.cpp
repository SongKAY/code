class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0;
        int r = 0;
        int result = INT_MAX;
        int sum = 0;
        int n = nums.size();
        while(r<n){
            sum += nums[r];
            if(sum<s)
                r ++;
            else{
                while(l<=r&&sum>=s){
                    result = min(result,r-l+1);
                    sum -= nums[l++];
                }
                r++;
            }
        }
        if(result==INT_MAX)
            result = 0;
        return result;
    }
};
