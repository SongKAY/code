class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                break;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int target = 0 - nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum==target){
                    result.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1])
                        l++;
                    while(l<r&&nums[r]==nums[r-1])
                        r--;
                    l++;
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else
                    r--;
            }
        }
        return result;
    }
};
