class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0;
        int r = nums.size()-1;
        sort(nums.begin(),nums.end());
        int result = 0;
        while(l<r){
            result += nums[r--] - nums[l++];
        }
        return result;
    }
};
