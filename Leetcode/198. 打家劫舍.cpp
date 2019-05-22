class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> yes(n,0);
        vector<int> no(n,0);
        vector<int> dp(n,0);
        int result = 0;
        yes[0] = nums[0];
        no[0] = 0;
        result = max(yes[0],no[0]);
        for(int i=1;i<n;i++){
            yes[i] = no[i-1] + nums[i];
            result = max(result,yes[i]);
            no[i] = max(yes[i-1],no[i-1]);
            result = max(result,no[i]);
        }
        return result;
    }
};
