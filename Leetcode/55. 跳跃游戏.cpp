class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxl = 0;
        int l = nums[0];
        for(int i=1;i<n;i++){
            if(l<i)
                return false;
            l = max(i+nums[i],l);
        }
        return true;
    }
};
