class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                break;
            if(i>=1&&nums[i]==nums[i-1])
                continue;
            int target = 0 - nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int a = nums[l];
                int b = nums[r];
                if(a+b==target){
                    result.push_back(vector<int>{nums[i],a,b});
                    while(l<r&&nums[l]==a)
                        l++;
                    while(l<r&&nums[r]==b)
                        r--;
                }
                else if(a+b<target)
                    l ++;
                else
                    r --;
            }
        }
        return result;
    }
};
