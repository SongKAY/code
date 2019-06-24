class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> mx(n,0);
        vector<int> my(n,0);
        mx[0] = nums[0];
        my[0] = nums[0];
        int result = mx[0];
        for(int i=1;i<nums.size();i++){
            mx[i] = max(nums[i],max(mx[i-1]*nums[i],my[i-1]*nums[i]));
            my[i] = min(nums[i],min(my[i-1]*nums[i],mx[i-1]*nums[i]));
            result = max(mx[i],result);
        } 
        return result;
    }
};
